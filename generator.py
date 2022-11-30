arr = [1, 10, 100, 200, 273, 300, 397, 440, 500]
ans = [4,  3,   7,   7,   1,   9,   8,   4,   3]

for i, n in enumerate(arr):
    open(f".{i}.in", "w").write(str(n))

for i, n in enumerate(ans):
    open(f".{i}.out", "w").write(str(n))
