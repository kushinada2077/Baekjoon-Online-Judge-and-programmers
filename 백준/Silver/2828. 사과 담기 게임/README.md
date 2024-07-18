# [Silver V] 사과 담기 게임 - 2828 

[문제 링크](https://www.acmicpc.net/problem/2828) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 구현

### 제출 일자

2024년 7월 18일 23:52:04

### 문제 설명

<p>Mirko has recently discovered an old video game. The screen of this game is divided into N columns. At the bottom of the screen, there is an M-columns-wide boat (M < N). The player can move this boat left or right during the game, but the boat must remain completely within the screen at all times. The boat initially occupies the leftmost M columns. </p>

<p>Apples are being dropped from the top of the screen. Each apple starts its fall at the top of one of the N columns, falling straight down until it reaches the bottom of the screen. The next apple starts its fall just after the current one has reached the bottom. </p>

<p>An apple is said to be picked up if the boat is placed so that it occupies the column down which the apple is falling when it reaches the bottom. The goal of the game is to pick up all of the apples, in a way that minimizes the distance that the boat must travel. </p>

### 입력 

 <p>The first line of input contains two space separated integers N and M (1 ≤ M < N ≤ 10). </p>

<p>The second line of input contains an integer J (1 ≤ J ≤ 20), the number of falling apples. </p>

<p>The following J lines contain the column positions of those apples, in the order in which they will fall.</p>

### 출력 

 <p>The only line of output must contain the minimal distance that the boat must travel in order to pick up all the apples. </p>

