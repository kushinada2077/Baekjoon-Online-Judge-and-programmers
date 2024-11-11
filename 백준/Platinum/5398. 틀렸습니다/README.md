# [Platinum II] 틀렸습니다 - 5398 

[문제 링크](https://www.acmicpc.net/problem/5398) 

### 성능 요약

메모리: 43364 KB, 시간: 136 ms

### 분류

이분 매칭

### 제출 일자

2024년 11월 11일 14:10:30

### 문제 설명

<p>You are solving a crossword puzzle and you have already written down the answers to all questions. While filling in the answers in the diagram, you notice that some answers have overlapping letters that do not match, so you must have made some mistakes in the answers. Instead of checking your answers, you decide to write a computer program to find the maximum number of answers that could have been correct.</p>

### 입력 

 <p>The first line of the input contains a single number: the number of test cases to follow. Each test case has the following format:</p>

<ul>
	<li>One line with two integers H and V , satisfying 1 ≤ H,V ≤ 500: the number of horizontal and vertical words, respectively.</li>
	<li>H lines, one for each horizontal word, each with two integers x and y and a string W, satisfying 0 ≤ x,y ≤ 1, 000 and 1 ≤ Length(W) ≤ 1, 000: the location of the first letter and the answer.</li>
	<li>V lines, one for each vertical word, each with two integers x and y and a string W, satisfying 0 ≤ x,y ≤ 1, 000 and 1 ≤ Length(W) ≤ 1, 000: the location of the first letter and the answer.</li>
</ul>

<p>Integers and strings on the same line are separated by single spaces. No pair of horizontal words will overlap, nor will any pair of vertical words. The words consist of upper case letters only.</p>

<p>The top left corner of the diagram is at x = y = 0, x runs in the horizontal direction, and y runs in the vertical direction (downwards).</p>

### 출력 

 <p>For every test case in the input, the output should contain a single number, on a single line: the maximum number of answers that can fit in the crossword.</p>

