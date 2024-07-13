# [Silver IV] 2+1 세일 - 11508 

[문제 링크](https://www.acmicpc.net/problem/11508) 

### 성능 요약

메모리: 2412 KB, 시간: 16 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2024년 7월 13일 16:49:00

### 문제 설명

<p>There is a promotional offer in a bookstore “Take 3, pay for the 2 more expensive ones”. So, each customer who picks 3 books gets the cheapest one for free. Of course, the customer can take even more books and, depending on the way the books are arranged into groups of three, get the cheapest one in each group for free.</p>

<p>For example, let the prices of the books taken by the customer be: 10 3 2 4 6 4 9. If he arranges them into groups: (10, 3, 2), (4, 6, 4) and (9), he will get the books priced 2 from the first group for free and the book priced 4 from the second group. We can see that he won’t get anything for free from the third group because it contains only one book.</p>

<p>The lady working in the bookstore is well-intentioned and she always wants to lower the price for each customer as much as possible. For given book prices, help the lady arrange the books into groups in the best way possible, so that the total price the customer has to pay is minimal.</p>

<p>Please note: The lady doesn’t have to arrange the books into groups so that each group contains exactly 3 books, but the number of books in a group needs to be between 1 and 3, inclusively. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 100 000), the number of books the customer bought.</p>

<p>Each of the following N lines contains a single integer C<sub>i</sub> (1 ≤ C<sub>i</sub> ≤ 100 000), the price of each book. </p>

### 출력 

 <p>The first and only line of output must contain the required minimal price.</p>

