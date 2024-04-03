# [Silver I] 효율적인 해킹 - 1325 

[문제 링크](https://www.acmicpc.net/problem/1325) 

### 성능 요약

메모리: 3468 KB, 시간: 2444 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 4월 3일 14:03:59

### 문제 설명

<p>Mayco has recently been hired as a security consultant for a well-known software company. At the moment, he’s working on his first assignment – trying to determine which of the company’s servers would be the best targets for potential attackers. It is a bit difficult, though, because some of the servers “trust” some of the others. If an attacker compromises a server, he or she can also freely access all servers that trust it (and servers that trust them, and so on).</p>

<p>By definition, the importance of a server S is the number of servers the attacker would be able to access if he compromised S. The most important servers are those with the highest importance. (Note that there can be more than one most important server. This is also illustrated in the example below.)</p>

<p>The network consists of N computers, numbered 1 to N, inclusive. The trust between computers is described by M ordered pairs (A,B) of numbers, denoting that computer A trusts computer B. The trust is not assumed to be mutual – i.e., if a computer A trusts computer B, it does not necessarily imply that computer B trusts computer A.</p>

### 입력 

 <p>The first line of input contains the numbers N and M. Each of the following M lines contains two integers, A and B, denoting that computer A trusts computer B.</p>

### 출력 

 <p>The output shall contain one line with the numbers of all of the most important servers. The numbers must be listed in increasing order and separated by single spaces.</p>

