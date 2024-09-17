# [Silver I] 음식물 피하기 - 1743 

[문제 링크](https://www.acmicpc.net/problem/1743) 

### 성능 요약

메모리: 2260 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 9월 17일 18:08:38

### 문제 설명

<p>Farmer John's farm was flooded in the most recent storm, a fact only aggravated by the information that his cows are deathly afraid of water. His insurance agency will only repay him, however, an amount depending on the size of the largest "lake" on his farm.</p>

<p>The farm is represented as a rectangular grid with N (1 ≤ N ≤ 100) rows and M (1 ≤ M ≤ 100) columns. Each cell in the grid is either dry or submerged, and exactly K (1 ≤ K ≤ N×M) of the cells are submerged. As one would expect, a lake has a central cell to which other cells connect by sharing a long edge (not a corner). Any cell that shares a long edge with the central cell or shares a long edge with any connected cell becomes a connected cell and is part of the lake.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, M, and K</li>
	<li>Lines 2..K+1: Line i+1 describes one submerged location with two space separated integers that are its row and column: R and C</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The number of cells that the largest lake contains.</li>
</ul>

