from collections import deque


def solution(bridge_length, weight, truck):
    answer,onweight,popcnt = 0,0,0
    counter, ontruck, truck = deque([]), deque([]),deque(truck)
    while truck or ontruck:
        for i in range(len(counter)):
            counter[i] += 1
            if counter[i] > bridge_length - 1:
                onweight -= ontruck[0]
                ontruck.popleft()
                popcnt += 1
        for i in range(popcnt):
            counter.popleft()
        if popcnt != 0:
            popcnt = 0

        if truck:
            if weight - onweight >= truck[0]:
                onweight += truck[0]
                ontruck.append(truck.popleft())
                counter.append(0)

        answer += 1
    return answer


truck = [7, 4, 5, 6]
solution(2, 10, truck)
