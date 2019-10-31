import gsheet
from pathlib import Path
import sys

ROM_PATH = Path(sys.argv[1])


def item_type_to_item_id(type: int) -> int:
    if 0 <= type <= 5:
        return type

    if type == 6:
        return 0x3C

    if type == 7:
        return 6

    if type == 8:
        return 7

    if type == 9:
        return 8

    if type == 10:
        return 9

    if type == 11:
        return 0xA

    if type == 12:
        return 0xB

    if type == 13:
        return 0xC

    if type == 14:
        return 0xD

    if type == 15:
        return 0xE

    if type == 16:
        return 0xF

    if type == 17:
        return 0x10

    if type == 18:
        return 0x11

    if type == 19:
        return 0x12

    if type == 20:
        return 0x13

    if type == 21:
        return 0x14

    if type == 22:
        return 0x15

    if type == 23:
        return 0x16

    if type == 24:
        return 0x17

    if type == 25:
        return 0x18

    if type == 26:
        return 0x19

    if type == 27:
        return 0x1A

    if type == 28:
        return 0x1B

    if type == 29:
        return 0x1C

    if type == 30:
        return 0x1D

    if type == 31:
        return 0x1E

    if type == 32:
        return 0x1F

    if type == 33:
        return 0x20

    if type == 34:
        return 0x21

    if type == 35:
        return 0x22

    if type == 36:
        return 0x23

    if type == 37:
        return 0x24

    if type == 38:
        return 0x25

    if type == 39:
        return 0x26

    if type == 40:
        return 0x27

    if type == 41:
        return 0x28

    if type == 43:
        return 0x2A

    if type == 44:
        return 43

    if type == 45:
        return 0x32

    if type == 46:
        return 0x33

    if type == 47:
        return 0x34

    if type == 48:
        return 0x35

    if type == 49:
        return 0x36

    if type == 50:
        return 0x37

    if type == 51:
        return 0x38

    if type == 52:
        return 0x39

    if type == 53:
        return 120

    if type == 54:
        return 0x79

    if type == 55:
        return 0x7A

    if type == 56:
        return 0x7B

    if type == 57:
        return 0x7C

    if type == 58:
        return 0x7D

    if type == 59:
        return 0x30

    if type == 60:
        return 0x31

    if type == 61:
        return 0x2D

    if type == 62:
        return 0x2C

    if type == 63:
        return 0x2F

    if type == 64:
        return 0x71

    if type == 65:
        return 0x6E

    if type == 66:
        return 0x74

    return 0x7F

item_id_by_type_map = {type: item_type_to_item_id(type) for type in range(0, 67)}
item_type_by_id_map = {v: k for k, v in item_id_by_type_map.items()}

items = gsheet.Datasheet((ROM_PATH / "region_common" / "datasheets" / "Items.gsheet").open("rb").read()).make_str_dict()

print('{|class="wikitable"')
print("! ID !! Type !! Name !! Actor ID !! NPC key !! Jingle !! Getting flag !! Autosave")
print("|-")
for name, props in items.items():
    print(f"| {props['itemID']} || {item_type_by_id_map.get(props['itemID'], '-')} || {name} || {props['actorID']} || {props['npcKey']} || {props['jingle']} || {props['gettingFlag']} || {props['autoSave']['enabled']}")
    print("|-")
print("""|}""")
