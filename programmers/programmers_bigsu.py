def solution(numbers):
  answer = ''
  arr = sorted(numbers, key = lambda x : (str(x)[0],x),reverse=True)
  for i in range(len(arr)-1):
    if str(arr[i])[0] == str(arr[i+1])[0]:
      if int(str(arr[i])+str(arr[i+1]))<int(str(arr[i+1])+str(arr[i])):
        temp = arr[i]
        arr[i] = arr[i+1]
        arr[i+1] = temp
  answer = "".join(map(str, arr))
  answer = int(answer)
  answer = str(answer)
  return answer
#==================================
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x*3, reverse=True)
    return str(int(''.join(numbers)))
