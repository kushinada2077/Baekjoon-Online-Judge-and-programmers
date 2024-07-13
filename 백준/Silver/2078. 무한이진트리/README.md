# [Silver II] 무한이진트리 - 2078 

[문제 링크](https://www.acmicpc.net/problem/2078) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학

### 제출 일자

2024년 7월 13일 17:40:02

### 문제 설명

<p>Binary trees are a common data structure in computer science. In this problem we will look at an infinite binary tree where the nodes contain a pair of integers. The tree is constructed like this:</p>

<ul>
	<li>The root contains the pair (1, 1).</li>
	<li>If a node contains (a, b) then its left child contains (a + b, b) and its right child (a, a + b)</li>
</ul>

<p>Given the contents (a, b) of some node of the binary tree described above, suppose you are walking from the root of the tree to the given node along the shortest possible path. Can you find out how often you have to go to a left child and how often to a right child?</p>

### 입력 

 <p>The first line containing two integers i and j (1 ≤ i, j ≤ 2·10<sup>9</sup>) that represent a node (i, j). You can assume that this is a valid node in the binary tree described above.</p>

### 출력 

 <p>Print a single line containing two numbers l and r separated by a single space, where l is how often you have to go left and r is how often you have to go right when traversing the tree from the root to the node given in the input.</p>

