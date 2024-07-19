# [Silver I] 우리집엔 도서관이 있어 - 2872 

[문제 링크](https://www.acmicpc.net/problem/2872) 

### 성능 요약

메모리: 3192 KB, 시간: 28 ms

### 분류

그리디 알고리즘

### 제출 일자

2024년 7월 19일 21:43:30

### 문제 설명

<p>Mirko has a home library consisting of N books arranged one on top of the other in a narrow cabinet. Since being well trained in the secrets of alphabet in the previous task, he now wishes to arrange the books alphabetically, so that the book whose title comes first alphabetically ends up on top, and the alphabetically last one at the bottom of the pile. </p>

<p>Mirko can easily pull a book out of the cabinet, but it is difficult to push it back into the pile, so the book can only be returned to the top of the pile. Thus, the only available method of sorting the books is repeatedly pulling a book out of the pile and placing it on top of the pile. </p>

<p>The books are labelled with integers from 1 to N, in alphabetical order. Therefore, Mirko wants them to be ordered as (1, 2, ..., N), counting from the top. For example, if N = 3 and the starting order is (3, 2, 1), two moves are sufficient. First, he pulls out the book number 2 and places it on top, so the pile becomes (2, 3, 1). After that, he does the same with book number 1, thus the pile becomes (1, 2, 3). </p>

<p>Help Mirko by calculating the minimum number of moves needed to sort a given starting order. </p>

### 입력 

 <p>The first line of input contains the integer N (N ≤ 300 000). </p>

<p>Each of the next N lines contains a single positive integer. These N integers represent the order of Mirko’s books from top to bottom of the cabinet. Each of the integers 1, 2, ..., N appears exactly once. </p>

### 출력 

 <p>The first and only line of output must contain the required minimum number of moves. </p>

<p> </p>

