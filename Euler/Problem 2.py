zbroj = 0
a = 1
b = 2
while b<=4000000:
    if b%2 == 0:
        zbroj +=b
    c = b
    b = a + b
    a = c
print zbroj