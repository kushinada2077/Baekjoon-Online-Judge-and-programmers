n, s = map(int, input().split())
arr = list(map(int, input().split()))
tot = 0
ans = 0

def sol(k):
  global ans, tot
  if k == n:
    ans += (tot == s)    
    return
  
  sol(k + 1)
  tot += arr[k]
  sol(k + 1)
  tot -= arr[k]

sol(0)
if s == 0: ans -= 1
print(ans)