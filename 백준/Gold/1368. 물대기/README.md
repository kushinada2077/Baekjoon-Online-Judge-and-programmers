# [Gold II] 물대기 - 1368 

[문제 링크](https://www.acmicpc.net/problem/1368) 

### 성능 요약

메모리: 3660 KB, 시간: 8 ms

### 분류

그래프 이론, 최소 스패닝 트리

### 제출 일자

2024년 4월 9일 14:12:01

### 문제 설명

<p>Farmer John has decided to bring water to his N (1 <= N <= 300) pastures which are conveniently numbered 1..N. He may bring water to a pasture either by building a well in that pasture or connecting the pasture via a pipe to another pasture which already has water.</p>

<p>Digging a well in pasture i costs W_i (1 <= W_i <= 100,000). Connecting pastures i and j with a pipe costs P_ij (1 <= P_ij <= 100,000; P_ij = P_ji; P_ii=0).</p>

<p>Determine the minimum amount Farmer John will have to pay to water all of his pastures.</p>

### 입력 

 <p>* Line 1: A single integer: N</p>

<p>* Lines 2..N + 1: Line i+1 contains a single integer: W_i</p>

<p>* Lines N+2..2N+1: Line N+1+i contains N space-separated integers; the j-th integer is P_ij</p>

### 출력 

 <p>* Line 1: A single line with a single integer that is the minimum cost of providing all the pastures with water.</p>

<p> </p>

