# How many numbers to gen
t = 10**5

# Max of a number
# a = 10**5
a = 35569

with open("test.txt", "w") as f:
    for i in range(t):
        f.write(str(a) + " ")
