# [Silver IV] 지뢰 찾기 - 4396 

[문제 링크](https://www.acmicpc.net/problem/4396) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2024년 7월 11일 14:05:06

### 문제 설명

<p>The game Minesweeper is played on an n by n grid. In this grid are hidden m mines, each at a distinct grid location. The player repeatedly touches grid positions. If a position with a mine is touched, the mine explodes and the player loses. If a positon not containing a mine is touched, an integer between 0 and 8 appears denoting the number of adjacent or diagonally adjacent grid positions that contain a mine. A sequence of moves in a partially played game is illustrated below.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images3/Image1.gif" style="height:239px; width:160px"><img alt="" src="https://www.acmicpc.net/upload/images3/Image2.gif" style="height:239px; width:160px"><img alt="" src="https://www.acmicpc.net/upload/images3/Image3.gif" style="height:239px; width:160px">  </p>

<p>Here, n is 8, m is 10, blank squares represent the integer 0, raised squares represent unplayed positions, and the figures resembling asterisks represent mines. The leftmost image represents the partially played game. From the first image to the second, the player has played two moves, each time choosing a safe grid position. From the second image to the third, the player is not so lucky; he chooses a position with a mine and therefore loses. The player wins if he continues to make safe moves until only m unplayed positions remain; these must necessarily contain the mines.</p>

<p>Your job is to read the information for a partially played game and to print the corresponding board.</p>

### 입력 

 <p>The first line of input contains a single postitive integer n <= 10. The next n lines represent the positions of the mines. Each line represents the contents of a row using n characters: a period indicates an unmined positon while an asterisk indicates a mined position. The next n lines are each n characters long: touched positions are denoted by an x, and untouched positions by a period. The sample input corresponds to the middle figure above.</p>

### 출력 

 <p>Your output should represent the board, with each position filled in appropriately. Positions that have been touched and do not contain a mine should contain an integer between 0 and 8. If a mine has been touched, all positions with a mine should contain an asterisk. All other positions should contain a period.</p>

