input_data = input().split()

A = int(input_data[0])
B = int(input_data[1])

if B>=45:
  B-=45
  print('%d %d'%(A,B))
else:
  temp = 45-B
  temp = 60-temp
  if A>0:
   A-=1
   print('%d %d'%(A,temp))
  elif A==0:
    print('23 %d'%(temp))
