N = int(input())
ord_a = ord('a')

for i in range(N):
  cnt = [0] * 26
  s1, s2 = input().split(" ")
  
  for c in s1:
    cnt[ord(c) - ord_a] += 1
  for c in s2:
    cnt[ord(c) - ord_a] -= 1
  
  if cnt.count(0) == 26:
    print("Possible")
  else:
    print("Impossible") 