# [Gold III] 나눌 수 있는 부분 수열 - 3673 

[문제 링크](https://www.acmicpc.net/problem/3673) 

### 성능 요약

메모리: 10976 KB, 시간: 80 ms

### 분류

수학, 누적 합

### 제출 일자

2024년 8월 18일 00:56:08

### 문제 설명

<p>Given a sequence of positive integers, count all contiguous subsequences (sometimes called substrings, in contrast to subsequences, which may leave out elements) the sum of which is divisible by a given number. These subsequences may overlap. For example, the sequence (see sample input)</p>

<p>2,1,2,1,1,2,1,2</p>

<p>contains six contiguous subsequences the sum of which is divisible by four: the first to eighth number, the second to fourth number, the second to seventh number, the third to fifth number, the fourth to sixth number, and the fifth to seventh number.</p>

### 입력 

 <p>The first line of the input consists of an integer c (1 ≤ c ≤ 200), the number of test cases. Then follow two lines per test case.</p>

<p>Each test case starts with a line consisting of two integers d (1 ≤ d ≤ 1,000,000) and n (1 ≤ n ≤ 50,000), the divisor of the sum of the subsequences and the length of the sequence, respectively. The second line of a test case contains the elements of the sequence, which are integers between 1 and 1 000 000 000, inclusively.</p>

### 출력 

 <p>For each test case, print a single line consisting of a single integer, the number of contiguous subsequences the sum of which is divisible by d.</p>

