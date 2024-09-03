# [Platinum III] 스위치 - 1395 

[문제 링크](https://www.acmicpc.net/problem/1395) 

### 성능 요약

메모리: 3300 KB, 시간: 76 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리

### 제출 일자

2024년 9월 3일 19:47:31

### 문제 설명

<p>Farmer John tries to keep the cows sharp by letting them play with intellectual toys. One of the larger toys is the lights in the barn. Each of the N (2 <= N <= 100,000) cow stalls conveniently numbered 1..N has a colorful light above it.</p>

<p>At the beginning of the evening, all the lights are off. The cows control the lights with a set of N pushbutton switches that toggle the lights; pushing switch i changes the state of light i from off to on or from on to off.</p>

<p>The cows read and execute a list of M (1 <= M <= 100,000) operations expressed as one of two integers (0 <= operation <= 1).</p>

<p>The first kind of operation (denoted by a 0 command) includes two subsequent integers S_i and E_i (1 <= S_i <= E_i <= N) that indicate a starting switch and ending switch. They execute the operation by pushing each pushbutton from S_i through E_i inclusive exactly once.</p>

<p>The second kind of operation (denoted by a 1 command) asks the cows to count how many lights are on in the range given by two integers S_i and E_i (1 <= S_i <= E_i <= N) which specify the inclusive range in which the cows should count the number of lights that are on.</p>

<p>Help FJ ensure the cows are getting the correct answer by processing the list and producing the proper counts.</p>

### 입력 

 <p>* Line 1: Two space-separated integers: N and M</p>

<p>* Lines 2..M+1: Each line represents an operation with three space-separated integers: operation, S_i, and E_i</p>

### 출력 

 <p>* Lines 1..number of queries: For each output query, print the count as an integer by itself on a single line.</p>

