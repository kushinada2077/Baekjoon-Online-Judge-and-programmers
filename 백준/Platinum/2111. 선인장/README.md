# [Platinum II] 선인장 - 2111 

[문제 링크](https://www.acmicpc.net/problem/2111) 

### 성능 요약

메모리: 7324 KB, 시간: 196 ms

### 분류

임의 정밀도 / 큰 수 연산, 이중 연결 요소, 선인장, 그래프 이론

### 제출 일자

2024년 10월 10일 13:38:37

### 문제 설명

<p>Cactus is a connected undirected graph in which every edge lies on at most one simple cycle. Intuitively cactus is a generalization of a tree where some cycles are allowed. Your task first is to verify if the given graph is a cactus or not. Important diﬀerence between a cactus and a tree is that a cactus can have a number of spanning subgraphs that are also cactuses. The number of such subgraphs (including the graph itself) determines cactusness of a graph (this number is one for a cactus that is just a tree). The cactusness of a graph that is not a cactus is considered to be zero.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/cactus.png" style="height:255px; width:563px"></p>

<p>The first graph on the picture is a cactus with cactusness 35. The second graph is not a cactus because edge (2, 3) lies on two cycles. The third graph is not a cactus because it is not connected.</p>

### 입력 

 <p>The first line of the input file contains two integer numbers n and m (1 ≤ n ≤ 20000, 0 ≤ m ≤ 1000). Here n is the number of vertices in the graph. Vertices are numbered from 1 to n. Edges of the graph are represented by a set of edge-distinct paths, where m is the number of such paths.</p>

<p>Each of the following m lines contains a path in the graph. A path starts with an integer number k<sub>i</sub> (2 ≤ k<sub>i</sub> ≤ 1000) followed by k<sub>i</sub> integers from 1 to n. These k<sub>i</sub> integers represent vertices of a path. Path can go to the same vertex multiple times, but every edge is traversed exactly once in the whole input file. There are no multiedges in the graph (there is at most one edge between any two vertices).</p>

### 출력 

 <p>Write to the output file a single integer number — the cactusness of the given graph. Note that cactusness can be quite a large number.</p>

