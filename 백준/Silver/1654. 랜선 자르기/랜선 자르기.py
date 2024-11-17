k, n = map(int, input().split())
arr = [int(input()) for _ in range(k)]

# 결정 문제: 각 랜선을 길이 x로 잘랐을 때 랜선의 갯수가 n개 이상인가? (== x 길이로 잘랐을 때 문제의 조건을 만족하는가)
def f(x):
  tot = 0
  for v in arr:
    tot += v // x
  
  return tot >= n
  

# 최대 랜선 길이는 2^31 -1이고, lo가 우리가 써야 하는 값이므로 hi가 오른쪽으로 한 칸 비켜준다
lo = 1
hi = 2 ** 31

while lo + 1 < hi:
  mid = (lo + hi) // 2

  if f(mid): lo = mid
  else: hi = mid

print(lo)