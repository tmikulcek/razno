popis = []
zbroj = 0
for a in range(2000001):
    popis.append(1)
popis[0] = 0
popis[1] = 0
for a in range(2000001):
    if popis[a] == 1:
        b = a
        zbroj += a
        print a
        while b<=2000000:
            b += a
            if b <=2000000:
                popis[b]=0
print zbroj