# 쿼리 한 번에 O(N)인데 100000번 반복
# O(NM) 10^5 * 10^5 = 10^10

# 이분 탐색을 이용하면 쿼리 한 번에 O(lgN) 100000번 반복
# O(MlgN)
# lg100000 = 17
# 1700000


# x가 arr 안에 존재하는지
# x는 x 이상이다
# False인 구간 => < x
# f(x) = 우리가 찾는 수 x <= arr[i]


# x == 0
# 1 3 5 8 10


n = int(input())
arr = list(map(int, input().split()))
m = int(input())

# 이분 탐색을 위해 정렬
arr.sort()

xList = list(map(int, input().split()))
for x in xList:
  # 찾고자 하는 숫자 x

  # 1. 결정 문제 정의 => f(x) = x <= arr[i]
  # x 이상인 가장 처음의 숫자

  # F F F F T T T....
  # 우리는 T인 구간의 값을 찾아야 하므로 T인 구간이 오른쪽 => hi를 쓴다
  # => lo가 한 칸 비켜줘야 한다

  lo = -1
  hi = n
  
  # lo 다음 칸이 hi일 때 종료
  while lo + 1 < hi:
    # 정수형 나눗셈 해주기
    mid = (lo + hi) // 2

    # mid에 대한 결정 문제의 값이 어떤지 
    # mid는 T인 구간에 있다 and T인 구간에서 움직이는 건 hi다
    if x <= arr[mid]: hi = mid
    # mid인 F인 구간에 있다 and F인 구간에서 움직이는 건 lo다
    else: lo = mid
    
  # while문을 탈출한 순간 lo, hi는 결정 문제의 경계에 있다
  # 우리가 써야 하는 건 hi
  
  # hi는 x <= arr[i]를 만족하는 가장 처음의 i
  
  # hi == n이면 배열 인덱스는 n - 1까지니까 outOfBound 에러가 나므로 예외처리
  if hi == n: print(0)
  elif arr[hi] == x:
    print(1)
  else:
    print(0)