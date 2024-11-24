n, m = map(int, input().split())
seq = []
used = [0 for _ in range(9)]

def sol(k): 
  if m == k:
    for i in seq: print(i, end=' ')
    print()
    return
  
  for i in range(1, n + 1):
    if used[i]: continue
    used[i] = 1
    seq.append(i)
    sol(k + 1)
    used[i] = 0
    seq.pop()

sol(0)