a = int(input())
b = int(input())
c = int(input())
product = str(a * b * c)
ans = [0] * 10

for num in product:
  ans[int(num)] += 1

for n in ans:
  print(n)

# print("\n".join(map(str, ans)))