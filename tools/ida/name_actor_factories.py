import binascii
import idaapi  # type: ignore
import idautils  # type: ignore
import ida_hexrays as hr  # type: ignore
import idc  # type: ignore
import os
import struct
import sys
import typing
import yaml

StructSize = 0x58
StructCount = 629
Address = 0x7101BCC898

actors = list()

for i in range(StructCount):
    print("[%u/%u]" % (i+1, StructCount))
    entry = idaapi.get_many_bytes(Address + StructSize*i, StructSize)
    make_fn = struct.unpack('<Q', entry[0x0:0x8])[0]
    resources = []
    for resource_idx in range(8):
      resource_name_ptr = struct.unpack(
          '<Q', entry[0x8+8*resource_idx:0x8+8*(resource_idx+1)])[0]
      if resource_name_ptr:
        resources.append(idc.GetString(resource_name_ptr))
    name_ptr = struct.unpack('<Q', entry[0x50:0x58])[0]
    name = idc.GetString(name_ptr)

    actors.append({"name": name, "resources": resources})

    function_name = "act::%s::make" % (name)
    idc.MakeNameEx(make_fn, function_name, idc.SN_NOWARN)

with open("/home/leo/projects/la/re/actors.yml", "w") as f:
  yaml.dump(actors, f)
