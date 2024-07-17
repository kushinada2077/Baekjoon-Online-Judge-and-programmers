def f(n):
  cnt = 0
  s = str(n)
  for c in s:
    if c == '6':
      cnt += 1
    else: cnt = 0
    if cnt == 3: return True
  return False
  
n = int(input())
cnt = 0
num = 666
while True:
  if f(num): cnt += 1 
  if cnt == n: 
    print(num)
    break
  num += 1