def s2i(s):
  if s == "W": return 0
  return 1
def f(x, y):
  ret = 0
  for i in range(x, x + 8):
    for j in range(y, y + 8):
      if (i + j) % 2 != s2i(board[i][j]): ret += 1
  
  return min(ret, 64 - ret)

n, m = map(int, input().split())
board = [input() for i in range(n)]
ans = 0x3f3f3f3f
for i in range(n - 7):
  for j in range(m - 7):
    ans = min(ans, f(i, j))

print(ans)