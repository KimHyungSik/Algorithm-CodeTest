import itertools
def solution(numbers):
    sieve = [True for x in range(10000000)]
    sieve[0] = False
    sieve[1] = False
    for x in range(2, 10000000):
        if sieve[x] == True:
            for y in range(x+x, 10000000, x):  
                sieve[y] = False
    answer = 0
    event = 0
    for x in range(1,len(numbers)+1):
        event = list(itertools.permutations(numbers, x))
        for y in event:
            if sieve[int("".join(y))] == True:
                answer+=1
                sieve[int("".join(y))] = False
    return answer
