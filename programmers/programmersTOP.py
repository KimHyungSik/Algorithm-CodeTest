def solution(heights):
    answer = []
    for i in range(len(heights)):
        answer.append(0)
        for j in range(i-1,-1,-1):
            if heights[j]>heights[i]:
                answer[i] = j+1
                break
    return answer