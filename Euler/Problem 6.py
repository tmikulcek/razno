import math
zbroj1 = 0
zbroj2 = 0
for a in range(1,101):
    b = a*a
    zbroj1 += b
print zbroj1
for a in range(1,101):
    zbroj2 += a
print zbroj2
zbroj2 = zbroj2*zbroj2
print zbroj2
print zbroj2-zbroj1
