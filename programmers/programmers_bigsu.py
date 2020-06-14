def solution(numbers):
  answer = ''
  arr = sorted(numbers, key = lambda x : (str(x)[0],x),reverse=True)
  for i in range(len(arr)-1):
    if str(arr[i])[0] == str(arr[i+1])[0] and arr[i]%10 < arr[i+1]%10:
      temp = arr[i]
      arr[i] = arr[i+1]
      arr[i+1] = temp
  answer = "".join(map(str, arr))
  answer = int(answer)
  answer = str(answer)
  return answer
