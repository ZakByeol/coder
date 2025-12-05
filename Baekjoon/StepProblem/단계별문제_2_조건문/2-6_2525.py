while 1:
	A,B = map(int, input().split())
	if A >= 0 and A<=23 and B>= 0 and B<=59:
		break
	else:
		continue

while 1:
    C = int(input())
    if C>= 0 and C<=59:
        break
    else:
        continue

if A == 23:
    if B<C:
        A -= 1
        B = 60 + (B-C)
    else:
        B = B-C

elif A==0:
    if B<C:
        B = 60 + (B-C)
        A = 23
    else:
        B = B-C
else:
    if B<C:
        A -= 1
        B = 60 + (B-C)
    else:
        B = B-C

print(A, B)