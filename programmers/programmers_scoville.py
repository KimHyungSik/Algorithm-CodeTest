import heapq
def solution(scoville, k):
    answer = 0
    hot = []
    for i in scoville:
      heapq.heappush(hot, i)
    for i in range(len(hot)):
      print(hot)
      if hot[0]>=k:
        return answer
      if hot[0]<k and len(hot)>1:
        heapq.heappush(hot,heapq.heappop(hot)+(heapq.heappop(hot)*2))
        answer+=1
    return -1
