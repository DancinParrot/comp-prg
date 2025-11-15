from sys import stdin


def export(count, valid):
    print()
    print("{} lines read from stdin.".format(count))
    print("Lines written to input.txt.".format(count))
    with open("input.txt", "w") as f:
        f.write(str(count) + "\n")
        for l in valid:
            f.write(l + "\n")


c = 0
valid = []
for l in stdin:
    line = l.rstrip()
    if line:
        valid.append(line)
        c += 1
export(c, valid)
