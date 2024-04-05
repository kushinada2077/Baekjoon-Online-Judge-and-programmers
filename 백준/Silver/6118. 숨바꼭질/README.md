# [Silver I] 숨바꼭질 - 6118 

[문제 링크](https://www.acmicpc.net/problem/6118) 

### 성능 요약

메모리: 3760 KB, 시간: 16 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 4월 5일 11:59:16

### 문제 설명

<p>Bessie is playing hide and seek (a game in which a number of players hide and a single player (the seeker) attempts to find them after which various penalties and rewards are assessed; much fun usually ensues).</p>

<p>She is trying to figure out in which of N (2 <= N <= 20,000) barns conveniently numbered 1..N she should hide. She knows that FJ (the seeker) starts out in barn 1. All the barns are connected by M (1 <= M <= 50,000) bidirectional paths with endpoints A_i and B_i (1 <= A_i <= N; 1 <= B_i <= N; A_i != B_i); it is possible to reach any barn from any other through the paths.</p>

<p>Bessie decides that it will be safest to hide in the barn that has the greatest distance from barn 1 (the distance between two barns is the smallest number of paths that one must traverse to get from one to the other). Help Bessie figure out the best barn in which to hide.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..M+1: Line i+1 contains the endpoints for path i: A_i and B_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: On a single line, print three space-separated integers: the index of the barn farthest from barn 1 (if there are multiple such barns, print the smallest such index), the smallest number of paths needed to reach this barn from barn 1, and the number of barns with this number of paths.</li>
</ul>

<p> </p>

