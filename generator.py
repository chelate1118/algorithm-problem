"""
Test-Case Generator
"""

import random
from subprocess import Popen, PIPE

p = [random.randrange(1, 10) for _ in range(20)]
n = [random.randrange(1, 501) for _ in range(20)]
a = []

for i in range(20):
    ANS = 0
    with Popen("./.ojw_exe", stdout=PIPE, stdin=PIPE, stderr=PIPE) as process:
        ANS = int(process.communicate(input=f'{p[i]} {n[i]}'.encode())[0])
    with open(f"./input/.{i}.in", "w", encoding="UTF-8") as inp:
        inp.write(f"{p[i]} {n[i]}")
    with open(f"./output/.{i}.out", "w", encoding="UTF-8") as out:
        out.write(f"{ANS}")
    a.append(ANS)

print(p)
print(n)
print(a)
