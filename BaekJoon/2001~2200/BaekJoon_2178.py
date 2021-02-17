from collections import deque
dx = [0,0,1,-1]
dy = [1,-1,0,0]



N,M = map(int, input().split())

Map = [list(map(int, list(input()))) for _ in range(N)]
queue = deque([[0,0]])
visited = [[False]*M for _ in range(N)]
count = [[0] * M for _ in range(N)]
visited[0][0] =True
count[0][0] = 1

while queue:
  x, y = queue.popleft()

  for i in range(4):
    nx, ny = x + dx[i], y + dy[i]
    if 0<=nx<N and 0<=ny<M:
      if not visited[nx][ny] and Map[nx][ny] == 1:
        queue.append([nx, ny])
        visited[nx][ny] = True
        count[nx][ny] = count[x][y] + 1

print(count[N-1][M-1])
