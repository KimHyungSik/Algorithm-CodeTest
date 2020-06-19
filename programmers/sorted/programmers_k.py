def solution(array, commands):
    answer = []
    for i in commands:
        if i[0] == i[1]:
            answer.append(array[i[0]-1])
        else:
            temp = array[i[0]-1:i[1]]
            temp.sort()
            answer.append(temp[i[2]-1])
    return answer