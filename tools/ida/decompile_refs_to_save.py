import binascii
import idaapi  # type: ignore
import idautils  # type: ignore
import ida_hexrays as hr  # type: ignore
import idc  # type: ignore
import os
import struct
import sys
import typing

total = len(list(idautils.DataRefsTo(0x7101CBB200+0x5F20+0x248)))
for i, ea in enumerate(idautils.DataRefsTo(0x7101CBB200+0x5F20+0x248)):
  print(i, total)
  try:
    idaapi.decompile(ea)
  except:
    pass
