# [Platinum II] Frequent values - 6515 

[문제 링크](https://www.acmicpc.net/problem/6515) 

### 성능 요약

메모리: 9012 KB, 시간: 996 ms

### 분류

자료 구조, mo's, 오프라인 쿼리, 세그먼트 트리

### 제출 일자

2024년 10월 24일 16:57:26

### 문제 설명

<p>You are given a sequence of n integers
a<sub>1</sub> , a<sub>2</sub> , ... , a<sub>n</sub>
in non-decreasing order. In addition to that, you are given several
queries
consisting of indices i and j (<i>1
≤ i ≤ j ≤ n</i>). For each query, determine the
most
frequent value among the integers a<sub>i</sub> , ... , a<sub>j</sub>.
</p>

### 입력 

 <p>
The input consists of several test cases.
Each test case starts with a line containing two integers n
and q (<i>1 ≤ n, q ≤ 100000</i>).
The next line contains n integers
a<sub>1</sub> , ... , a<sub>n</sub>
(<i>-100000 ≤ a<sub>i</sub> ≤ 100000</i>, for each <i>i ∈ {1, ..., n}</i>)
separated by spaces.
You can assume that for each <i>i ∈ {1, ..., n-1}: a<sub>i</sub> ≤ a<sub>i+1</sub></i>.
The following q lines contain one query each,
consisting of two integers i and j
(<i>1 ≤ i ≤ j ≤ n</i>), which indicate the boundary indices for the
query.
</p>
<p>
The last test case is followed by a line containing a single <i>0</i>.
</p>

### 출력 

 <p>
For each query, print one line with one integer:
The number of occurrences of the most frequent value within
the given range.
</p>

