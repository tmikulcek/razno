a = 1
korak = 2
n = 0
zbroj = 1
while a < 1001*1001:
    a += korak
    zbroj += a
    n += 1
    if n == 4:
        n = 0
        korak += 2
print zbroj