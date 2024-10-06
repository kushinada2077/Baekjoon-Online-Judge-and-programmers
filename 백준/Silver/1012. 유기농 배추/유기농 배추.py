from collections import deque
# 인접 리스트

# 각 정점마다 인접한 정점에 대한 정보를 배열로 보관
# => 정점이 n개이므로 n개의 배열이 필요함
# => 보통 문제마다 최대 정점의 개수가 몇 개인지 주어지므로 그 값에 맞춰서 미리 선언을 해둠

# 스택, 큐를 쓰냐에 따라 DFS인지 BFS인지 바뀝니다

# dir 0 ~ 3
# x, y => (1, 1)
# dir = 1
# nx = x + dx[dir] = 1 + 0 = 1
# ny = y + dy[dir] = 1 + 1 = 2
# (2, 1), (1, 2), (0, 1), (1, 0)

  

# 2차원 배열 상에서의 BFS, DFS
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]



def bfs(x, y, m, n, board, vis):
  q = deque()
  vis[x][y] = 1
  q.append((x, y))

  while len(q) > 0:
    curX, curY = q.popleft()
    for dir in range(4):
      nx = curX + dx[dir]
      ny = curY + dy[dir]
      if nx < 0 or nx >= m or ny < 0 or ny >= n: continue
      if vis[nx][ny] or board[nx][ny] == 0 : continue
      q.append((nx, ny))
      vis[nx][ny] = 1


T = int(input())

while T:
  T -= 1
  ans = 0
  m, n, k = map(int, input().split())
  board = [[0 for i in range(51)] for i in range(51)]
  vis = [[0 for i in range(51)] for i in range(51)]
  for i in range(k):
    x, y = map(int, input().split())
    # 배추가 심어져 있다고 표시
    board[x][y] = 1 

  # 모든 정점을 돌면서 탐색을 실행할 수 있는지 확인
  for i in range(m):
    for j in range(n):
      # 이미 방문한 정점이거나 배추가 심어져 있지 않은 정점(board 값이 0)이면 continue
      if vis[i][j] == 1 or board[i][j] == 0: continue
      # 그렇지 않다면 탐색 시작 가능, 컴포넌트 개수 +1
      ans += 1
      bfs(i, j, m, n, board, vis)

  print(ans)