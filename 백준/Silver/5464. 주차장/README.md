# [Silver II] 주차장 - 5464 

[문제 링크](https://www.acmicpc.net/problem/5464) 

### 성능 요약

메모리: 2160 KB, 시간: 0 ms

### 분류

자료 구조, 구현, 큐, 시뮬레이션

### 제출 일자

2025년 1월 27일 00:29:46

### 문제 설명

<p>A parking garage has N parking spaces, numbered from 1 to N inclusive. The garage opens empty each morning and operates in the following way throughout the day. Whenever a car arrives at the garage, the attendants check whether there are any parking spaces available. If there are none, then the car waits at the entrance until a parking space is released. If a parking space is available, or as soon as one becomes available, the car is parked in the available parking space. If there is more than one available parking space, the car will be parked at the space with the smallest number. If more cars arrive while some car is waiting, they all line up in a queue at the entrance, in the order in which they arrived. Then, when a parking space becomes available, the first car in the queue (i.e., the one that arrived the earliest) is parked there.</p>

<p>The cost of parking in dollars is the weight of the car in kilograms multiplied by the specific rate of its parking space. The cost does not depend on how long a car stays in the garage.</p>

<p>The garage operator knows that today there will be M cars coming and he knows the order of their arrivals and departures. Help him calculate how many dollars his revenue is going to be today.</p>

<p>Write a program that, given the specific rates of the parking spaces, the weights of the cars and the order in which the cars arrive and depart, determines the total revenue of the garage in dollars.</p>

### 입력 

 <p>Your program must read from standard input the following data:</p>

<ul>
	<li>The first line contains the integers N and M, separated by a space.</li>
	<li>The next N lines describe the rates of the parking spaces. The sth of these lines contains a single integer Rs, the rate of parking space number s in dollars per kilogram.</li>
	<li>The next M lines describe the weights of the cars. The cars are numbered from 1 to M inclusive in no particular order. The kth of these M lines contains a single integer Wk, the weight of car k in kilograms.</li>
	<li>The next 2*M lines describe the arrivals and departures of all cars in chronological order. A positive integer i indicates that car number i arrives at the garage. A negative integer -i indicates that car number i departs from the garage. No car will depart from the garage before it has arrived, and all cars from 1 to M inclusive will appear exactly twice in this sequence, once arriving and once departing. Moreover, no car will depart from the garage before it has parked (i.e., no car will leave while waiting on the queue). </li>
</ul>

<ul>
	<li>1 ≤ N ≤ 100 The number of parking spaces</li>
	<li>1 ≤ M ≤ 2,000 The number of cars</li>
	<li>1 ≤ Rs ≤ 100 The rate of parking space s in dollars per kilogram</li>
	<li>1 ≤ Wk ≤ 10,000 The weight of car k in kilograms</li>
</ul>

### 출력 

 <p>Your program must write to standard output a single line containing a single integer: the total number of dollars that will be earned by the garage operator today. </p>

