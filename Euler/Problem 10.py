b = 3
a = 2
zbroj = 5
popis = [2,3]
while a<=2000000:
    c = 0
    b +=2
    for d in range(len(popis)):
        if b%popis[d] == 0:
            c = 1
            break
    if c == 0:
        a += 1
        popis.append(b)
        zbroj +=b
        print a," ",b
print b