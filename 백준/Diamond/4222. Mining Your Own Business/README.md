# [Diamond IV] Mining Your Own Business - 4222 

[문제 링크](https://www.acmicpc.net/problem/4222) 

### 성능 요약

메모리: 29440 KB, 시간: 748 ms

### 분류

단절점과 단절선, 이중 연결 요소, 그래프 이론

### 제출 일자

2024년 10월 15일 18:14:00

### 문제 설명

<p>John Digger is the owner of a large illudium phosdex mine. The mine is made up of a series of tunnels that meet at various large junctions. Unlike some owners, Digger actually cares about the welfare of his workers and has a concern about the layout of the mine. Speciﬁcally, he worries that there may a junction which, in case of collapse, will cut off workers in one section of the mine from other workers (illudium phosdex, as you know, is highly unstable). To counter this, he wants to install special escape shafts from the junctions to the surface. He could install one escape shaft at each junction, but Digger doesn’t care about his workers that much. Instead, he wants to install the minimum number of escape shafts so that if any of the junctions collapses, all the workers who survive the junction collapse will have a path to the surface.</p>

<p>Write a program to calculate the minimum number of escape shafts and the total number of ways in which this minimum number of escape shafts can be installed.</p>

### 입력 

 <p>The input consists of several test cases. The ﬁrst line of each case contains a positive integer N (N ≤ 5·10<sup>4</sup>) indicating the number of mine tunnels. Following this are N lines each containing two distinct integers s and t, where s and t are junction numbers. Junctions are numbered consecutively starting at 1. Each pair of junctions is joined by at most a single tunnel. Each set of mine tunnels forms one connected unit (that is, you can get from any one junction to any other).</p>

<p>The last test case is followed by a line containing a single zero.</p>

### 출력 

 <p>For each test case, display its case number followed by the minimum number of escape shafts needed for the system of mine tunnels and the total number of ways these escape shafts can be installed. You may assume that the result ﬁts in a signed 64-bit integer.</p>

<p>Follow the format of the sample output.</p>

