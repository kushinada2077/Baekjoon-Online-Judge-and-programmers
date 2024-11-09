# [Platinum III] 룩 배치하기 - 9525 

[문제 링크](https://www.acmicpc.net/problem/9525) 

### 성능 요약

메모리: 4120 KB, 시간: 180 ms

### 분류

이분 매칭

### 제출 일자

2024년 11월 9일 18:33:14

### 문제 설명

<p>Chess inspired problems are a common source of exercises in algorithms classes. Starting with the well known 8-queens problem, several generalizations and variations were made. One of them is the N-rooks problem, which consists of placing N rooks in an N by N chessboard in such a way that they do not attack each other.</p>

<p>Professor Anand presented the N-rooks problem to his students. Since rooks only attack each other when they share a row or column, they soon discovered that the problem can be easily solved by placing the rooks along a main diagonal of the board. So, the professor decided to complicate the problem by adding some pawns to the board. In a board with pawns, two rooks attack each other if and only if they share a row or column and there is no pawn placed between them. Besides, pawns occupy some squares, which gives an additional restriction on which squares the rooks may be placed on.</p>

<p>Given the size of the board and the location of the pawns, tell Professor Anand the maximum number of rooks that can be placed on empty squares such that no two of them attack each other.</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 100) representing the number of rows and columns of the board. Each of the next N lines contains a string of N characters. In the i-th of these strings, the j-th character represents the square in the i-th row and j-th column of the board. The character is either “.” (dot) or the uppercase letter “X”, indicating respectively an empty square or a square containing a pawn.</p>

### 출력 

 <p>Output a line with an integer representing the maximum number of rooks that can be placed on the empty squares of the board without attacking each other.</p>

