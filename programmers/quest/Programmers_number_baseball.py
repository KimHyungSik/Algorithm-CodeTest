def solution(baseball):
  answer = 0
  again = 0
  for x in range(324,329):
    again = 0
    if str(x)[0] == str(x)[1] or str(x)[0] == str(x)[2] or str(x)[1] == str(x)[2] or str(x)[0] == '0' or str(x)[1] == '0' or str(x)[2] == '0':
      continue
    for yagoo, st, ba in baseball:
      strike = 0
      ball = 0
      for te in range(3):
        if str(yagoo)[te] == str(x)[te]:
          strike+=1
          continue
        if str(yagoo)[te] in str(x):
          ball+=1
      if strike != st or ball != ba:
        again = 1
    if again == 0 : 
      answer += 1   
    
  return answer
