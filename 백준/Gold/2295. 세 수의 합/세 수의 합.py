# 집합 원소의 개수
n = int(input())
u = []

for _ in range(n):
    u.append(int(input()))
u.sort()

sumSet = set()
for i in range(n-1):
    for j in range(i, n-1):
        if u[i] + u[j] <= u[n-1]:
            sumSet.add(u[i] + u[j])

sumList = sorted(sumSet)

def bs(n, u, sumList):
    for maxIndex in range(n-1, -1, -1):
        maxValue = u[maxIndex]
        for sumElem in sumList:
            if sumElem >= maxValue:
                break
            left = -1
            right = maxIndex
            value = u[maxIndex] - sumElem

            while(left +1 < right):
                mid = (left + right) // 2 
                if value > u[mid]:
                    left = mid
                else :
                    right = mid
            
            if u[right] == value: return maxValue

            
print(bs(n, u, sumList))