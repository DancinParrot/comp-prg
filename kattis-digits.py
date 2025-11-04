i = 0


def digits(n):
    global i
    i += 1
    l = len(str(n))
    # Converting a string to int with int() is costly. Hence, don't do it with a large string since input is a number with <= 1 mil digits.
    if l < 8 and int(n) == 1:
        return i
    return digits(l)


while True:
    s = input()

    if s == "END":
        break
    i = 0
    print(digits(s))
