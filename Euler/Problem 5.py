n = 20
i = 0
while (i == 0):
    i = 1
    for a in range(1 , 20):
        if n % a != 0:
            i = 0
            n += 20
print n