def solution(genres, plays):
    answer = []
    onecchk=[0 for i in range(len(genres))]
    Dgenres = {}
    for g,p in zip(genres, plays):
        if g in Dgenres:
            Dgenres[g].append(p)
        else:
            Dgenres[g] = [p]
    for g in genres:
        Dgenres[g] = sorted(Dgenres[g], reverse=True)
    Dgenres = sorted(Dgenres.items(), reverse=True, key=lambda x:sum(x[1]))
    for d in Dgenres:
        for nd in d[1][:2]:
            for a in range(len(genres)):
                if d[0] == genres[a] and nd == plays[a] and onecchk[a] == 0:
                  answer.append(a)
                  onecchk[a] = 1   
                  break     
    return answer
