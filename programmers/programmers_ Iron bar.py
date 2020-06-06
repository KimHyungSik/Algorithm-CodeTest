def solution(arrangement):
    answer = 0
    chkarr = []
    for i in range(len(arrangement)):
        if arrangement[i] == ')' and arrangement[i-1] == '(':
            answer += len(chkarr)
        elif arrangement[i] == '(' and arrangement[i+1] != ')':
            chkarr.append(0)
        elif arrangement[i] == ')' and arrangement[i-1] != '(':
            answer += 1
            chkarr.pop()
        
    return answer
