num = input().split(" ")
an = 0

for i in range(int(num[0], int(num[1])+1)):
    an += sum(map(int, str(i)))

print(an)