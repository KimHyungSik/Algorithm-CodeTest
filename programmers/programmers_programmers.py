from collections import deque

def solution(progresses, speeds):
  answer = []
  popcnt = 0
  Qprogresses = deque(progresses)
  Qspeeds = deque(speeds)
  while Qprogresses:
    for i in range(len(Qprogresses)):
      Qprogresses[i] += Qspeeds[i]       

    for j in range(len(Qprogresses)):
      if Qprogresses[j] >= 100:
        popcnt += 1
      elif Qprogresses[j]<100:
        break
    if popcnt != 0:
      answer.append(popcnt)
      for k in range(popcnt):
        Qprogresses.popleft()
        Qspeeds.popleft()
    popcnt = 0
  return answer
