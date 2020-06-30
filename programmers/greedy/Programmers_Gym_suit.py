def solution(n, lost, reserve):
  student = [1 for x in range(n)]
  for x in reserve:
    student[x-1] += 1
  for x in lost:
    student[x-1] -= 1

  for x in range(len(student)):
    if student[x] == 0:
      if x ==0 and student[1] == 2:
        student[0] = 1
        student[1] = 1
      elif x == n-1 and student[x-1] == 2:
        student[x] = 1
        student[x-1] = 1
      elif x !=0 and x != n-1 :
        if student[x-1] == 2:
          student[x-1] = 1
          student[x] = 1
        elif student[x+1] == 2:
          student[x+1] = 1
          student[x] = 1
  return sum(map(lambda x : 1 if x == 2 else x ,student))