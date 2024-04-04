N = int(input())
nums = map(int, input().split(" "))
x = int(input())
sum = [0] * 2000001
ans = 0

for num in nums:
  if x > num and sum[x - num]:
    ans += 1
  sum[num] = 1    

print(ans)