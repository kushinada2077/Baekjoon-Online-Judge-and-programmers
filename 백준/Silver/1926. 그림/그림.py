import sys
from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

vis = [[0 for _ in range(505)] for _ in range(505)]    

def bfs(sy, sx):
  q = deque()
  ret = 0
  
  q.append((sy, sx))
  vis[sy][sx] = 1

  while len(q):
    y, x = q.popleft()       
    ret += 1  

    for dir in range(4):
      ny = y + dy[dir] 
      nx = x + dx[dir]
      # 내가 보고 있는 정점이 방문을 했다면
      if ny < 0 or ny >= n or nx < 0 or nx >= m: continue
      if vis[ny][nx] == 1 or board[ny][nx] == 0: continue
      q.append((ny, nx)) 
      vis[ny][nx] = 1
  
  return ret

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

ans = 0
ans2 = 0
for i in range(n):
  for j in range(m):
    if (vis[i][j] or board[i][j] == 0): continue
    ans += 1
    ans2 = max(ans2, bfs(i, j))

print(ans)
print(ans2)    