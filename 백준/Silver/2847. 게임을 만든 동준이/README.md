# [Silver IV] 게임을 만든 동준이 - 2847 

[문제 링크](https://www.acmicpc.net/problem/2847) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 1월 21일 15:41:38

### 문제 설명

<p>Mirko has developed his own video game. The game has N levels and each successfully completed level is worth a certain number of points, which add up to the player’s total score on an online rank list of all players. Mirko has ordered his levels by difficulty from the easiest to the most difficult, but he has made a mistake and made some difficult levels worth less points than some of the easier ones.</p>

<p>To overcome this problem, Mirko has decided to reduce the number of points for certain levels with the goal of making the point sequence strictly increasing (so in the end easier levels are worth less points than the difficult ones).</p>

<p>Help Mirko fix his video game in such a way that the total number of points reduced is minimal. Final points have to be positive. You can assume that a solution exists for each test case</p>

### 입력 

 <p>The first line of input contains one positive integer N (1 ≤ N ≤ 100), the number of levels.</p>

<p>The next N lines contain positive integers less than 20 000, the number of points that Mirko has associated with each level, from the first to the last level.</p>

### 출력 

 <p>The first and and only line of output should contain one number - the minimum total number of points Mirko has to subtract to fulfill requirements given in the task statement above.</p>

