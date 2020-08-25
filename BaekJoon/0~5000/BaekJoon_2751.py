count = int(input())
num = []

for i in range(count):
    num.append(int(input()))

num = sorted(num)

for i in num:
    print(i)