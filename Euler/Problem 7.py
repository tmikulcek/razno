b = 3
a = 2
while a<10001:
    c = 0
    b +=2
    for d in range(3,b/2):
        if b%d == 0:
            c = 1
            break
    if c == 0:
        a += 1
        print a," ",b
print b