# [Silver II] 도영이가 만든 맛있는 음식 - 2961 

[문제 링크](https://www.acmicpc.net/problem/2961) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

백트래킹, 비트마스킹, 브루트포스 알고리즘

### 제출 일자

2024년 7월 16일 14:47:17

### 문제 설명

<p>"Perket" is a widely known and delicious meal. For perket to be what it is, cooks must carefully choose the ingredients to get the fullest taste possible while keeping the meal traditional. </p>

<p>You have N ingredients at your disposal. For each we know its sourness S and bitterness B. When using multiple ingredients, the total sourness is the product of sourness amounts of all ingredients, while the total bitterness is the sum of bitterness amounts of all ingredients. </p>

<p>As everyone knows, perket is supposed to be neither sour nor bitter; we want to choose the ingredients so that the absolute difference between sourness and bitterness is the smallest. </p>

<p>Also, it is necessary to use at least one ingredient; you can't serve water as the main course. </p>

### 입력 

 <p>The first line contains the integer N (1 ≤ N ≤ 10), the number of ingredients at our disposal. </p>

<p>Each of the next N lines contains two integers separated by a space, the sourness and bitterness of each ingredient. </p>

<p>The input data will be such that, if we make a meal with all ingredients, both the sourness and bitterness will be less than 1000000000. </p>

### 출력 

 <p>Output the smallest possible difference between sourness and bitterness. </p>

<p> </p>

