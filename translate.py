#!/usr/bin/python3
import re
content = ''
try:
    while True:
        content = content + input()
except EOFError:
    pass
content = re.sub(r'#include "fol/\w+?\.hpp"', r'\n// Depends translated', content)
print(content)
