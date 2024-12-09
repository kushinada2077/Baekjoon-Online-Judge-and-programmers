# [Gold III] ls - 5015 

[문제 링크](https://www.acmicpc.net/problem/5015) 

### 성능 요약

메모리: 2200 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 12월 9일 12:32:19

### 문제 설명

<p>You are implementing an operating system, and now need to write a program to list files in a directory: `ls'. You want the user to be able to list only les that match a given pattern that can include wildcards (*), for example *.c. A wildcard matches zero or more characters of any kind.</p>

### 입력 

 <p>The first line contains a string P, containing 1-100 characters 'a'-'z', '*' and '.'. This is the pattern. The second line contains an integer N, 1 ≤ N ≤ 100, which is the number of files in the directory. Then follows N lines containing the names of the files in the directory. Each line is a string containing 1{100 characters 'a'-'z' and '.'.</p>

### 출력 

 <p>The output shall consist of the filenames that match the pattern, P, each on its own line, in the same order that they were given as input.</p>

