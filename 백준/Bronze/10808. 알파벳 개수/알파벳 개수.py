s = input()
alpha = [0 for i in range(26)]
for c in s:
  alpha[ord(c) - ord('a')] += 1
  
for i in alpha:
  print(i, end=" ")