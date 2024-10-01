# [Platinum III] 도시 계획 - 11097 

[문제 링크](https://www.acmicpc.net/problem/11097) 

### 성능 요약

메모리: 2892 KB, 시간: 56 ms

### 분류

플로이드–워셜, 그래프 이론, 강한 연결 요소, 최단 경로

### 제출 일자

2024년 10월 1일 13:25:55

### 문제 설명

<p>The town of Pezinok wants to expand by building a new neighborhood. They hired some famous architects to design it, and your friend Jano is one of them. He is in charge of the road network. It is common to make one-way roads these days, so Jano went all out and decided to make all the roads one-way. (Of course, a pair of junctions can be connected by two roads – one in each direction.)</p>

<p>Once Jano made a map showing the planned roads, he noticed that some parts of the neighborhood might not be reachable from other parts. To estimate the impact of this issue, he decided to use a systematic approach: he took a piece of paper and wrote everything down. Namely, for each junction j he listed all other junctions that are (directly or indirectly) reachable from j. We call this information the reachability list of a road network.</p>

<p>But then Jano’s hard drive crashed and he lost all the plans he had made. The only thing he has left is the piece of paper with the reachability list.</p>

<p>Help Jano reconstruct his original road network. Of course, many different road networks can produce the same reachability list. Therefore, Jano asked you to find the smallest possible road network that has the given reachability list. That should help him reconstruct his original plans.</p>

<p>Find a road network with the smallest possible number of roads that has the given reachability list.</p>

### 입력 

 <p>The first line of the input file contains an integer t specifying the number of test cases. Each test case is preceded by a blank line.</p>

<p>Each test case starts with a line containing an integer n (1 ≤ n ≤ 300), denoting the number of junctions. The junctions are numbered 1 through n. Next, n lines follow, each containing a string of length n. The i-th of these lines specifies which junctions are reachable from junction i. Namely, the j-th character in the line is 1 if junction j is reachable from i and 0 otherwise. (Note that for each i, junction i is reachable from itself.)</p>

<p>The reachability list is consistent – it describes at least one real road network.</p>

### 출력 

 <p>For each test case, output the smallest road network that corresponds to the given reachability list. The first line of the description should contain the number of roads m (which has to be as small as possible). Each of the next m lines should contain two integers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n) such that there is a one-way road going from junction a<sub>i</sub> to junction b<sub>i</sub>.</p>

<p>You can print the roads in any order. If there are multiple optimal solutions, output any of them.</p>

