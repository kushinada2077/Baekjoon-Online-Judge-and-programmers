# [Diamond V] 좀비 아포칼립스 - 10319 

[문제 링크](https://www.acmicpc.net/problem/10319) 

### 성능 요약

메모리: 336364 KB, 시간: 556 ms

### 분류

최대 유량

### 제출 일자

2024년 11월 7일 13:08:50

### 문제 설명

<p>You and the rest of your team are stuck in a town during the zombie apocalypse of 2020. You all might be infected with the virus and hence you will have to find your way to one of the medical facilities to get a cure before you also become zombies. Because you are scientists you quickly realize that it is safer to try and sneak your way past the zombies than to recklessly start fighting them. Obviously the zombies are everywhere so some streets might take more time to sneak through than others. It is also obvious that by splitting up into smaller groups it is easier to move around undetected.</p>

<p>Furthermore, since these zombies have not mutated to the extent that they actually have eyes in the back of their heads, it might be easy to cross some streets in one direction while hard or impossible to cross them in the other direction.</p>

<p>How many of you can sneak past all the zombies and get to a medical facility in time?</p>

<p style="text-align:center"><a href="https://xkcd.com/734"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/upload/images2/outbreak.png" style="height:252px; width:740px"></a></p>

<p style="text-align:center"> </p>

### 입력 

 <p>On the first line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with a single integer n (1 ≤ n ≤ 1 000): the number of locations in the town.</li>
	<li>one line with three space-separated integers i, g and s (1 ≤ i ≤ n and 1 ≤ g ≤ 100 and 1 ≤ s ≤ 100): the starting location of your group, the number of people in it, and the number of time steps you have to get to the safety of a medical facility, respectively.</li>
	<li>one line with a single integer m (1 ≤ m ≤ n): the number of medical facilities in the town.</li>
	<li>m lines, each with a single integer x (1 ≤ x ≤ n): the location of each of the medical facilities.</li>
	<li>one line with a single integer r (0 ≤ r ≤ 1 000): the number of roads in the town.</li>
	<li>r lines, each with four space-separated integers a, b, p and t (1 ≤ a, b ≤ n and a ≠ b and 1 ≤ p ≤ 100 and 1 ≤ t ≤ 100), indicating that there is a road from a to b, which p people can enter at every time step and takes t timesteps to traverse.</li>
</ul>

<p>There are at most two roads – one in each direction – between any pair of locations. The locations are safe enough to wait at for any amount of time and do not have a limit on the number of people that can be there.</p>

### 출력 

 <p>Per test case:</p>

<p>one line with a single integer: the largest number of people that can get to a medical facility in time.</p>

