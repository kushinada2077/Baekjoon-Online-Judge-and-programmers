# [Silver III] 먹을 것인가 먹힐 것인가 - 7795 

[문제 링크](https://www.acmicpc.net/problem/7795) 

### 성능 요약

메모리: 2220 KB, 시간: 24 ms

### 분류

이분 탐색, 정렬, 두 포인터

### 제출 일자

2025년 1월 26일 23:38:53

### 문제 설명

<p>Deep down under the sea, there’re two kinds of living organism, let’s say A and B. A is B’s predator, but A will only eat B if and only if its size is strictly bigger than its prey. For example, let the size of A = {8, 1, 7, 3, 1} and B = {3, 6, 1}, then there are 7 pairs of A – B where A > B: 8 – 3, 8 – 6, 8 – 1, 7 – 3, 7 – 6, 7 – 1, 3 – 1. </p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/ee(1).png" style="height:164px; width:209px"></p>

<p>Given the size of each organism in A and B, write a program to count how many pair of A - B are there such that A is strictly bigger than B. Your program should be efficient as the number of organism may be large. </p>

### 입력 

 <p>The first line of input contains an integer T, the number of test cases follow. </p>

<p>Each case will begin with two integers N (1 ≤ N ≤ 20,000) and M (1 ≤ M ≤ 20,000), denoting the number of organism A and B respectively. The next line will contain N positive integers represent the size of each A organism. The third line will contain M positive integers represent the size of each B organism. </p>

### 출력 

 <p>For each case, print on a single line the number of pair A – B such that A is strictly larger than B. </p>

<p> </p>

