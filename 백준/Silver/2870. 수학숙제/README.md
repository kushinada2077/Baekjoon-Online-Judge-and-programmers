# [Silver IV] 수학숙제 - 2870 

[문제 링크](https://www.acmicpc.net/problem/2870) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

파싱, 정렬, 문자열

### 제출 일자

2024년 7월 9일 18:04:56

### 문제 설명

<p>Little Mirko wasn’t paying attention in math class, so the teacher has decided to give him a tedious assignment to solve during the weekend. </p>

<p>The teacher has given him a text consisting of N lines, containing only digits and lower case letters of the English alphabet. Mirko has to find all numbers in the text and print them out in a nondecreasing sequence. He also has to omit any leading zeros that the numbers may have in the text. </p>

<p>The numbers can be uniquely determined by scanning through the text and always taking the largest possible number, i.e. delimited only by letters or line beginnings/ends. For example, the solution of 01a2b3456cde478 is 1, 2, 478, 3456. </p>

<p>Since Mirko is as slow as the snail from the previous task, he has asked you to write him a program to quickly solve his assignment, so that he can go play with Slavko as soon as possible. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 100), the number of lines of the text. </p>

<p>The next N lines contain the text, consisting exclusively of lowercase English letters and decimal digits. Each line of the text is at most 100 characters long. </p>

### 출력 

 <p>The output must contain M lines, where M is the number of numbers found in the provided text. Each line must contain a single number from the text. The numbers must be arranged in a nondecreasing sequence. </p>

<p>Note: The test data will ensure that M will never exceed 500. </p>

