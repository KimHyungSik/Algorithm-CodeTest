def solution(citations):
  arr = sorted(citations, reverse = True
  for i in range(len(arr)):
    if arr[i] <= len(arr[:i])+1:
      return arr[i]

  return 0
