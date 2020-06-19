def solution(answers):
    answer = []
    s1 = [1, 2, 3, 4, 5]
    s2 = [2, 1, 2, 3, 2, 4, 2, 5]
    s3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    score = [0,0,0]
    for i in range(len(answers)):
        if s1[i%5] == answers[i]:
            score[0] += 1
        if s2[i%8] == answers[i]:
            score[1] += 1
        if s3[i%10] == answers[i]:
            score[2] += 1
    for x in range(len(score)):
        if score[x] == max(score):
            answer.append(x+1)
    return answer
