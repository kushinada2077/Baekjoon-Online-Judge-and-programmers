import sys
from collections import deque

def OOB(r, c): return r < 0 or r >= n or c < 0 or c >= m
def bfs(r, c):
  ret = 0
  q = deque()
  q.append([r, c])
  vis[r][c] = 1
  while len(q):
    r, c = q.popleft() # 현재 위치 (방금 방문함)
    ret += 1
    for dir in range(4):
      nr = r + dr[dir] # 탐색 위치
      nc = c + dc[dir]
      if OOB(nr, nc) or vis[nr][nc] or board[nr][nc] == 0: continue # OOB도 아니고 방문도 안한 정점이면
      q.append([nr, nc]) 
      vis[nr][nc] = 1  # 방문 표시
  return ret

n, m = map(int, input().split())
ans_n = 0
ans_s = 0
board = []
for i in range(n):
  board.append(list(map(int, input().split()))) 
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
vis = [[0 for i in range(m)] for j in range(n)]

for i in range(n):
  for j in range(m):
    if vis[i][j] or board[i][j] == 0: continue
    ans_n += 1
    ans_s = max(ans_s, bfs(i, j))
print(ans_n, ans_s, sep="\n")