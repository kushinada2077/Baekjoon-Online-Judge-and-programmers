# [Platinum II] 돼지 잡기 - 1658 

[문제 링크](https://www.acmicpc.net/problem/1658) 

### 성능 요약

메모리: 12660 KB, 시간: 68 ms

### 분류

최대 유량

### 제출 일자

2024년 11월 6일 18:33:18

### 문제 설명

<p>Mirko works on a pig farm that consists of M locked pig-houses and Mirko can't unlock any pighouse because he doesn't have the keys. Customers come to the farm one after another. Each of them has keys to some pig-houses and wants to buy a certain number of pigs. </p>

<p>All data concerning customers planning to visit the farm on that particular day are available to Mirko early in the morning so that he can make a sales-plan in order to maximize the number of pigs sold. </p>

<p>More precisely, the procedure is as following: the customer arrives, opens all pig-houses to which he has the key, Mirko sells a certain number of pigs from all the unlocked pig-houses to him, and, if Mirko wants, he can redistribute the remaining pigs across the unlocked pig-houses. </p>

<p>An unlimited number of pigs can be placed in every pig-house. </p>

<p>Write a program that will find the maximum number of pigs that he can sell on that day.</p>

### 입력 

 <p>The first line of input file contains two integers M and N, 1 ≤ M ≤ 1000, 1 ≤ N ≤ 100, number of pighouses and number of customers. Pig houses are numbered from 1 to M and customers are numbered from 1 to N. </p>

<p>The next line contains M integeres, for each pig-house initial number of pigs. The number of pigs in each pig-house is greater or equal to 0 and less or equal to 1000. </p>

<p>The next N lines contains records about the customers in the following form ( record about the i-th customer is written in the (i+2)-th line): </p>

<p>A K<sub>1</sub> K<sub>2</sub> ... K<sub>A</sub> B </p>

<p>It means that this customer has key to the pig-houses marked with the numbers K<sub>1</sub>, K<sub>2</sub>, ..., K<sub>A</sub> (sorted nondecreasingly ) and that he wants to buy B pigs. Numbers A and B can be equal to 0.</p>

### 출력 

 <p>The first and only line of the output file should contain the number of sold pigs. </p>

<p> </p>

