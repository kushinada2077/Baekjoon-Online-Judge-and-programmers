# [Silver I] 삼각 그래프 - 4883 

[문제 링크](https://www.acmicpc.net/problem/4883) 

### 성능 요약

메모리: 13044 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 1월 21일 16:55:34

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images/trigraph.png" style="float:right; height:342px; width:261px">Here’s a simple graph problem: Find the shortest path from the top-middle vertex to the bottom-middle vertex in a given tri-graph. A tri-graph is an acyclic graph of (N ≥ 2) rows and exactly 3 columns. Unlike regular graphs, the costs in a tri-graph are associated with the vertices rather than the edges. So, considering the example on the right with N = 4, the cost of going straight down from the top to bottom along the middle vertices is 7+ 13+ 3+ 6 = 29. The layout of the directional edges in the graph are always the same as illustrated in the ﬁgure.</p>

### 입력 

 <p>Your program will be tested on one or more test cases. Each test case is speciﬁed using N + 1 lines where the ﬁrst line speciﬁes a single integer (2 ≤ N ≤ 100,000) denoting the number of rows in the graph. N lines follow, each specifying three integers representing the cost of the vertices on the ith row from left to right. The square of each cost value is less than 1,000,000.</p>

<p>The last case is followed by a line with a single zero.</p>

### 출력 

 <p>For each test case, print the following line:</p>

<pre>k. n</pre>

<p>Where k is the test case number (starting at one,) and n is the least cost to go from the top-middle vertex to the bottom-middle vertex.</p>

