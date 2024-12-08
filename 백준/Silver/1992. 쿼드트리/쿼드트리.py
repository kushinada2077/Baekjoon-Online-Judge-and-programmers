n = int(input())
board = [input() for _ in range(n)]

# 정의: 좌표 (y, x)부터 크기가 sz인 사각형의 원소가 모두 같나? 
def allTheSame(y, x, sz):
  for i in range(0, sz):
    for j in range(0, sz):
      if board[y + i][x + j] != board[y][x]: return False

  return True

# 정의: 좌표 (y, x)부터 크기가 sz인 사각형을 압축하는 함수
def solve(y, x, sz):
# 기저 사례: 사각형의 모든 원소가 같은 경우
  # 지금 보는 사각형의 모든 원소가 같은가?(== 바로 압축할 수 있는가)
  if allTheSame(y, x, sz):
    return str(board[y][x])

  # 압축이 바로 되지 않는 경우 (== 문제를 분할하는 경우)

  # (y, x)
  upperLeft = solve(y, x, sz // 2)
  # (y, x + sz / 2)
  upperRight = solve(y, x + sz // 2, sz // 2)
  # (y + sz / 2, x)
  lowerLeft = solve(y + sz // 2, x, sz // 2)
  # (y + sz / 2, x + sz / 2)
  lowerRight = solve(y + sz // 2, x + sz // 2, sz // 2)

  # 병합
  return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")"

print(solve(0, 0, n))