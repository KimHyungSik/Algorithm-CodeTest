from collections import deque
def solution(priorities, location):
  answer = None
  counter = 0
  printer = deque(priorities);
  loc = deque((i for i in range(len(priorities))));

  while(1):
    for i in range(len(printer)):
      if(printer[0] < printer[i]):
        printer.append(printer.popleft())
        loc.append(loc.popleft())
        break
      if(i == len(printer)-1):
        printer.popleft()
        answer = loc.popleft()
        counter += 1
        break
    if answer == location:
      return counter   
  
