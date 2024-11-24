n = int(input())
col = [0 for _ in range(20)]
diag_l = [0 for _ in range(100)]
diag_r = [0 for _ in range(100)]
ans = 0

def sol(r):
  global ans
  if r == n:
    ans += 1
    return

  for c in range(n):
    if col[c] or diag_l[c + r] or diag_r[c - r + 20]: continue
    col[c] = diag_l[c + r] = diag_r[c - r + 20] = 1
    sol(r + 1)
    col[c] = diag_l[c + r] = diag_r[c - r + 20] = 0

sol(0)
print(ans)