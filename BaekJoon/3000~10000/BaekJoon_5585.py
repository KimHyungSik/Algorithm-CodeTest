price = int(input())
count= 0

Money = 1000 - price

while Money > 0:
    if Money >= 500:
        count +=1
        Money -= 500
        continue
    elif Money >= 100:
        count += 1
        Money -= 100
        continue
    elif Money >= 50:
        count += 1
        Money -= 50
        continue
    elif Money >= 10:
        count += 1
        Money -= 10
        continue
    elif Money >= 5:
        count += 1
        Money -= 5
        continue
    elif Money >= 1:
        count += 1
        Money -= 1
        continue

print(count)
