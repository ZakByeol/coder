while 1:
    H = int(input())
    if H >= 0 and H<=23:
        break
    else:
        continue
while 1:
    M = int(input())
    if M>= 0 and M<=59:
        break
    else:
        continue
# H,M의 조건 만족 구문

if H == 0 and M <45:
    H = 23
    M = 60 + (M-45)
else:
    if M<45:
        H = H-1
        M = 60 + (M-45)
    else:
        M = M-45

print(H, M)

# 런타임에러 ValueError 가 뜨는데 왜 이렇지...?

H,M = map(int, input().split())

if H == 0 and M <45:
    H = 23
    M = 60 + (M-45)
else:
    if M<45:
        H = H-1
        M = 60 + (M-45)
    else:
        M = M-45

print(H, M)

# 이렇게 하니까 됨... 뭐지..?
# 알아보니 해당 백준 사이트에서 값을 입력할때 '첫째줄'에서 할당과정이 일어나기 때문에
# split함수를 쓰면서 코드를 짜야함

while 1:
	H,M = map(int, input().split())
	if H >= 0 and H<=23 and M>= 0 and M<=59:
		break
	else:
		continue

if H == 0 and M <45:
    H = 23
    M = 60 + (M-45)
else:
    if M<45:
        H = H-1
        M = 60 + (M-45)
    else:
        M = M-45

print(H, M)

# 조건 추가한 코드임