# [Gold IV] 가장 가까운 공통 조상 - 3584 

[문제 링크](https://www.acmicpc.net/problem/3584) 

### 성능 요약

메모리: 3636 KB, 시간: 8 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 최소 공통 조상, 트리

### 제출 일자

2024년 9월 12일 16:46:06

### 문제 설명

<p>A rooted tree is a well-known data structure in computer science and engineering. An example is shown below:</p>

<p style="text-align: center;"><img alt="" src="" style="height:278px; width:304px"></p>

<p>In the figure, each node is labeled with an integer from {1, 2,…,16}. Node 8 is the root of the tree. Node x is an ancestor of node y if node x is in the path between the root and node y. For example, node 4 is an ancestor of node 16. Node 10 is also an ancestor of node 16. As a matter of fact, nodes 8, 4, 10, and 16 are the ancestors of node 16. Remember that a node is an ancestor of itself. Nodes 8, 4, 6, and 7 are the ancestors of node 7. A node x is called a common ancestor of two different nodes y and z if node x is an ancestor of node y and an ancestor of node z. Thus, nodes 8 and 4 are the common ancestors of nodes 16 and 7. A node x is called the nearest common ancestor of nodes y and z if x is a common ancestor of y and z and nearest to y and z among their common ancestors. Hence, the nearest common ancestor of nodes 16 and 7 is node 4. Node 4 is nearer to nodes 16 and 7 than node 8 is.</p>

<p>For other examples, the nearest common ancestor of nodes 2 and 3 is node 10, the nearest common ancestor of nodes 6 and 13 is node 8, and the nearest common ancestor of nodes 4 and 12 is node 4. In the last example, if y is an ancestor of z, then the nearest common ancestor of y and z is y.</p>

<p>Write a program that finds the nearest common ancestor of two distinct nodes in a tree.</p>

### 입력 

 <p>The input consists of T test cases. The number of test cases (T ) is given in the first line of the input file. Each test case starts with a line containing an integer N , the number of nodes in a tree, 2 ≤ N ≤ 10,000 . The nodes are labeled with integers 1,2,...,N . Each of the next N −1 lines contains a pair of integers that represent an edge – the first integer is the parent node of the second integer. Note that a tree with N nodes has exactly N −1 edges. The last line of each test case contains two distinct integers whose nearest common ancestor is to be computed.</p>

### 출력 

 <p>Print exactly one line for each test case. The line should contain the integer that is the nearest common ancestor.</p>

