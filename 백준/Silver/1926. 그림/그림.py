from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
vis = [[0 for i in range(500)] for j in range(500)]

def bfs(sx, sy):
  ret = 0
  dq = deque()
  dq.append([sx, sy])
  vis[sx][sy] = 1 # 방문 체크
   
  while len(dq):
    x, y = dq.popleft() # 큐에서 뽑은 현재 좌표
    ret += 1
    for dir in range(4):
      nx = x + dx[dir] # 다음 x좌표
      ny = y + dy[dir] # 다음 y좌표
      if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
      if paper[nx][ny] == 0: continue
      if vis[nx][ny]: continue
      dq.append([nx, ny])
      vis[nx][ny] = 1
  return ret

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for i in range(n)]
ans1 = 0
ans2 = 0
for i in range(n):
  for j in range(m):
    if paper[i][j] == 1 and vis[i][j] == 0:
      ans1 += 1
      ans2 = max(ans2, bfs(i, j))

print(ans1, ans2, sep='\n')