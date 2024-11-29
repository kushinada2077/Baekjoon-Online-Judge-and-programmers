n, m = map(int, input().split())
isUsed = [0 for _ in range(10)]
seq = []

def sol(k):
  if k == m:
      for v in seq: print(v, end=" ")
      print()
      return
  
  st = 0
  if len(seq): st = seq[-1]
  for i in range(st + 1, n + 1):
     if isUsed[i]: continue
     isUsed[i] = 1
     seq.append(i)
     sol(k + 1)
     isUsed[i] = 0
     seq.pop()

sol(0)