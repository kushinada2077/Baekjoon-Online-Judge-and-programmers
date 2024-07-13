# [Silver V] 셀프 넘버 - 4673 

[문제 링크](https://www.acmicpc.net/problem/4673) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 구현, 수학

### 제출 일자

2024년 7월 13일 16:40:44

### 문제 설명

<p>In 1949 the Indian mathematician D.R. Kaprekar discovered a class of numbers called self-numbers. For any positive integer n, define d(n) to be n plus the sum of the digits of n. (The d stands for digitadition, a term coined by Kaprekar.) For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a starting point, you can construct the infinite increasing sequence of integers n, d(n), d(d(n)), d(d(d(n))), .... For example, if you start with 33, the next number is 33 + 3 + 3 = 39, the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, and so you generate the sequence</p>

<p>33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...</p>

<p>The number n is called a generator of d(n). In the sequence above, 33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57, and so on. Some numbers have more than one generator: for example, 101 has two generators, 91 and 100. A number with no generators is a self-number. There are thirteen self-numbers less than 100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97.</p>

<p>Write a program to output all positive self-numbers less than 10000 in increasing order, one per line.</p>

### 입력 

 Empty

### 출력 

 Empty

