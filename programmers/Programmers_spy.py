def solution(clothes):
    answer = 1
    Dclothes = {}
    for i in clothes:  
        Dclothes[i[1]] = 0
    for i in clothes:  
        Dclothes[i[1]] += 1
        
        
    if len(Dclothes) == 1:
        answer=Dclothes[clothes[0][1]]
    else:
        for i in Dclothes.keys():
            answer *= Dclothes[i]
        for i in Dclothes.keys():
            answer += Dclothes[i]
           
    return answer
