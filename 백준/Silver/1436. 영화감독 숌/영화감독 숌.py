def f(n):
  cnt = 0

  while n > 0:
    if n % 10 == 6: cnt += 1
    else: cnt = 0
    if cnt == 3: return True
    n //= 10

  return False

n = int(input())
num = 666
cnt = 0

while True:
  if f(num):
    cnt += 1
  if cnt == n:
    print(num)
    break
  num += 1