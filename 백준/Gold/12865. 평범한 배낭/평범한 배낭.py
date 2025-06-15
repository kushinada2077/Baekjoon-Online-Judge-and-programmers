N, K = map(int, input().split())
item = []

for i in range(N):
  w, v = map(int, input().split())
  item.append((w, v))

dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]

for i in range(1, N + 1):
  w, v = item[i - 1]
  for j in range(1, K + 1):
    dp[i][j] = dp[i - 1][j]
    if j - w >= 0:
      dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + v)
      
print(dp[N][K])