# [Diamond V] 리스크 - 3666 

[문제 링크](https://www.acmicpc.net/problem/3666) 

### 성능 요약

메모리: 4396 KB, 시간: 112 ms

### 분류

이분 탐색, 최대 유량, 매개 변수 탐색

### 제출 일자

2024년 11월 8일 17:20:27

### 문제 설명

<p>Risk is a board game played on a world map. This world is divided into regions by borders. Each region is controlled by a player (either you or one of your opponents). Any region that you control contains a positive number of your armies.</p>

<p>In each turn, you are allowed to move your armies. Each of your armies may either stay where it is, or move from a region to a bordering region under your control. The movements are performed one by one, in an order of your choice. At all times, each region must contain at least one army.</p>

<p>For strategic purposes, it is important to move your armies to regions that border your opponents’ regions and minimize the number of armies on your regions that are totally surrounded by other regions under your control. You want your weakest link, i.e., the border region with the minimum number of armies, to be as strong as possible. What is the maximum number of armies that can be placed on it after one turn?</p>

### 입력 

 <p>On the ﬁrst line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>One line with an integer n (1 ≤ n ≤ 100): the number of regions.</li>
	<li>One line with n integers a<sub>i</sub> (0 ≤ a<sub>i</sub> ≤ 100): the number of your armies on each region. A number 0 indicates that a region is controlled by your opponents, while a positive number indicates that it is under your control.</li>
	<li>n lines with n characters, where each character is either ‘Y’ or ‘N’. The i-th character of the j-th line is ‘Y’ if regions i and j border, and ‘N’ otherwise. This relationship is symmetric and the i-th character of the i-th line will always be ‘N’.</li>
</ul>

<p>In every test case, you control at least one region, and your opponents control at least one region. Furthermore, at least one of your regions borders at least one of your opponents’ regions.</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>One line with an integer: the maximum number of armies on your weakest border region after one turn of moving.</li>
</ul>

