# [Gold III] 최대 유량 - 6086 

[문제 링크](https://www.acmicpc.net/problem/6086) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

최대 유량, 그래프 이론, 구현, 시뮬레이션

### 제출 일자

2024년 10월 26일 01:43:02

### 문제 설명

<p>Farmer John always wants his cows to have enough water and thus has made a map of the N (1 <= N <= 700) water pipes on the farm that connect the well to the barn. He was surprised to find a wild mess of different size pipes connected in an apparently haphazard way. He wants to calculate the flow through the pipes.</p>

<p>Two pipes connected in a row allow water flow that is the minimum of the values of the two pipe's flow values. The example of a pipe with flow capacity 5 connecting to a pipe of flow capacity 3 can be reduced logically to a single pipe of flow capacity 3:</p>

<pre>  +---5---+---3---+    ->    +---3---+
</pre>

<p>Similarly, pipes in parallel let through water that is the sum of their flow capacities:</p>

<pre>    +---5---+
 ---+       +---    ->    +---8---+
    +---3---+
</pre>

<p>Finally, a pipe that connects to nothing else can be removed; it contributes no flow to the final overall capacity:</p>

<pre>    +---5---+
 ---+               ->    +---3---+
    +---3---+--
</pre>

<p>All the pipes in the many mazes of plumbing can be reduced using these ideas into a single total flow capacity.</p>

<p>Given a map of the pipes, determine the flow capacity between the well (A) and the barn (Z).</p>

<p>Consider this example where node names are labeled with letters:</p>

<pre>                 +-----------6-----------+
        A+---3---+B                      +Z
                 +---3---+---5---+---4---+
                         C       D
</pre>

<p>Pipe BC and CD can be combined:</p>

<pre>                 +-----------6-----------+
        A+---3---+B                      +Z
                 +-----3-----+-----4-----+
                             D
</pre>

<p>Then BD and DZ can be combined:</p>

<pre>                 +-----------6-----------+
        A+---3---+B                      +Z
                 +-----------3-----------+
</pre>

<p>Then two legs of BZ can be combined:</p>

<pre>                 B
        A+---3---+---9---+Z
</pre>

<p>Then AB and BZ can be combined to yield a net capacity of 3:</p>

<pre>        A+---3---+Z
</pre>

<p>Write a program to read in a set of pipes described as two endpoints and then calculate the net flow capacity from 'A' to 'Z'. All networks in the test data can be reduced using the rules here.</p>

<p>Pipe i connects two different nodes a_i and b_i (a_i in range 'A-Za-z'; b_i in range 'A-Za-z') and has flow F_i (1 <= F_i <= 1,000). Note that lower- and upper-case node names are intended to be treated as different.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N + 1: Line i+1 describes pipe i with two letters and an integer, all space-separated: a_i, b_i, and F_i</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that the maximum flow from the well ('A') to the barn ('Z')</li>
</ul>

