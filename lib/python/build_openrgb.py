import subprocess
import os
import sys
import re
KEYBOARDS = []

command = "grep -rl 'MCU = SN32F2' | sed -e 's/keyboards\///g' -e 's/\/rules.mk//g'| sort"
ret = subprocess.run(command, capture_output=True, shell=True)
BOARDS = ret.stdout.decode().split('\n')

for line in BOARDS:
    # We need to manipulate some non-standard directories
    if line.strip() != "" and line.strip() != "lib/python/build_all.py" and line.strip() != "lib/python/openrgb_all.py" and line.strip() != "lib/python/build_openrgb.py":
        if re.match("^(gmmk)",line.strip()):
            KEYBOARDS.append(line.strip()+"/rev2")
            KEYBOARDS.append(line.strip()+"/rev3")
        if re.match("^(keychron/k)",line.strip()):
            KEYBOARDS.append(line.strip())
            # keychron K series white don't have yet via/optical support
            if re.match("(?!.*white)",line.strip()):
                KEYBOARDS.append(line.strip()+"/optical")
        else: KEYBOARDS.append(line.strip())

error = False
for kb in KEYBOARDS:
    # We are building for different chips, and some things need a clean pass, so make sure it's clean
    build_command = f"qmk clean && qmk compile -kb {kb} -km all -j{os.cpu_count()}"
    if subprocess.run(build_command, shell=True).returncode != 0:
        error = True
if error:
    sys.exit(1)