# [Silver I] 컴백홈 - 1189 

[문제 링크](https://www.acmicpc.net/problem/1189) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

백트래킹, 브루트포스 알고리즘, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 8월 13일 15:59:58

### 문제 설명

<p>As every cow does occasionally, Bessie has lost herself in the woods! She desperately needs to get back to the barn but has no idea where to go.</p>

<p>The woods can be thought of as an R x C grid (1 <= R <= 5; 1 <= C <= 5). Bessie is located in the lower left corner at row 1, column 1; the barn is located in the upper right corner at in row R, column C.  Each square in the grid is either empty (denoted by '.') or blocked by a tree (denoted by 'T'). Bessie's square and the barn will always be empty.</p>

<p>From a given square, Bessie may move to any adjacent square (one that shares a long edge with Bessie's current square) as long as it is empty. As Bessie is quite a smart cow, she never visits a square twice on the way back to the barn.</p>

<p>Determine the number of different ways Bessie can take that lead her from her initial position back to the barn while visiting exactly K different squares (1 <= K <= R * C).</p>

<p>By way of example, consider this forest:</p>

<pre>        ....
        .T..
        ....
</pre>

<p>Bessie has a number of ways to get to the upper right corner, here are all seven of them and their path lengths (the number of squares visited):</p>

<pre>         cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f  
         bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde  
         a...  abcd  abc.  abcd  a...  a.gh  abc.  
Length:    6     6     6     8     8    10    6
</pre>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: R, C, and K</li>
	<li>Lines 2..R+1: Line i+1 contains the C characters representing row R+1-i of the forest (with no spaces)</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of different paths, visiting exactly K squares, that Bessie can take to get back to the barn. Note that this number will always fit into a signed 32-bit integer.</li>
</ul>

<p> </p>

