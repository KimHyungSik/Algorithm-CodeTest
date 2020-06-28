def solution(brown, yellow):
    temp = []
    start = 1
    end = yellow
    while start<=end:
      if start * end == yellow:
        temp.append([start,end])
        start+=1
        end-=1
      elif start * end < yellow:
        start+=1
      elif start * end > yellow: 
        end-=1
    for ans in range(len(temp)):
      if (temp[ans][0]+2)*(temp[ans][1]+2) - yellow == brown:
        return [max(temp[ans][0]+2,temp[ans][1]+2),min(temp[ans][0]+2,temp[ans][1]+2)]
