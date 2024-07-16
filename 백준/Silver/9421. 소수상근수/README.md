# [Silver I] 소수상근수 - 9421 

[문제 링크](https://www.acmicpc.net/problem/9421) 

### 성능 요약

메모리: 2268 KB, 시간: 88 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 7월 16일 14:25:36

### 문제 설명

<p>A Happy Number ☺ can be defined as follows. From a positive integer n, calculate the sum of square of each digit of n. Then from that sum, repeat the same process over and over again. This cycle terminates if and only if there is 1 in the sequence. Hence, we call the number n a happy number if it generates a finite sequence. Otherwise, the endless cycle occurs (1 never appears in the sequence). We may call the number generating an endless cycle an unhappy number . Observe the following examples: </p>

<p>700 is a happy number </p>

<ul>
	<li>7<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 49</li>
	<li>4<sup>2</sup> + 9<sup>2</sup> = 97</li>
	<li>9<sup>2</sup> + 7<sup>2</sup> = 130</li>
	<li>1<sup>2</sup> + 3<sup>2</sup> + 0<sup>2</sup> = 10</li>
	<li>1<sup>2</sup> + 0<sup>2</sup> = 1</li>
</ul>

<p>2 is not a happy number </p>

<ul>
	<li>2<sup>2</sup> = 4</li>
	<li>4<sup>2</sup> = 16</li>
	<li>1<sup>2</sup> + 6<sup>2</sup> = 37</li>
	<li>3<sup>2</sup> + 7<sup>2</sup> = 58</li>
	<li>5<sup>2</sup> + 8<sup>2</sup> = 89</li>
	<li>8<sup>2</sup> + 9<sup>2</sup> = 145</li>
	<li>1<sup>2</sup> + 4<sup>2</sup> + 5<sup>2</sup> = 42</li>
	<li>4<sup>2</sup> + 2<sup>2</sup> = 20</li>
	<li>2<sup>2</sup> + 0<sup>2</sup> = 4</li>
	<li>4<sup>2</sup> = 16</li>
	<li>... and never terminates </li>
</ul>

<p>A Prime Number is an integer greater than 1 that can be divided only by 1 and itself. Here are some prime numbers: 2, 3, 5, 7, 11, 13, 17, 19, … </p>

<p>A Happy Prime Number is a prime number which also satisfies the happy number condition such as 7, 13, 19, … </p>

<p>Your task is to write a program to show all happy prime numbers less than or equal to a given number n. (10 ≤ n ≤ 1000000) </p>

### 입력 

 <p>A positive number n is the only input of the program.</p>

### 출력 

 <p>The program prints all happy numbers in ascending order, one number in a line. </p>

