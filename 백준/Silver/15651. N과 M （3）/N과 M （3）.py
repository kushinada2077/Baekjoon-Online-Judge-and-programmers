n, m = map(int, input().split())
seq = []

def sol(k):
  if k == m:
      for v in seq: print(v, end=" ")
      print()
      return
  
  st = 0
  for i in range(1, n + 1):
     seq.append(i)
     sol(k + 1)
     seq.pop()

sol(0)