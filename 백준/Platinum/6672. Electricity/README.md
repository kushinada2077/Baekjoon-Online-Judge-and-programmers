# [Platinum III] Electricity - 6672 

[문제 링크](https://www.acmicpc.net/problem/6672) 

### 성능 요약

메모리: 3492 KB, 시간: 140 ms

### 분류

단절점과 단절선, 이중 연결 요소, 그래프 이론

### 제출 일자

2024년 10월 7일 12:54:12

### 문제 설명

<p>Blackouts and Dark Nights (also known as ACM++) is a company that provides electricity. The company owns several power plants, each of them supplying a small area that surrounds it. This organization brings a lot of problems - it often happens that there is not enough power in one area, while there is a large surplus in the rest of the country.</p>

<p>ACM++ has therefore decided to connect the networks of some of the plants together. At least in the first stage, there is no need to connect all plants to a single network, but on the other hand it may pay up to create redundant connections on critical places - i.e. the network may contain cycles. Various plans for the connections were proposed, and the complicated phase of evaluation of them has begun.</p>

<p>One of the criteria that has to be taken into account is the reliability of the created network. To evaluate it, we assume that the worst event that can happen is a malfunction in one of the joining points at the power plants, which might cause the network to split into several parts. While each of these parts could still work, each of them would have to cope with the problems, so it is essential to minimize the number of parts into which the network will split due to removal of one of the joining points.</p>

<p>Your task is to write a software that would help evaluating this risk. Your program is given a description of the network, and it should determine the maximum number of non-connected parts from that the network may consist after removal of one of the joining points (not counting the removed joining point itself).</p>

### 입력 

 <p>The input consists of several instances.</p>

<p>The first line of each instance contains two integers 1 <= P <= 10 000 and C >= 0 separated by a single space. P is the number of power plants. The power plants have assigned integers between 0 and P - 1. C is the number of connections. The following C lines of the instance describe the connections. Each of the lines contains two integers 0 <= p1, p2 < P separated by a single space, meaning that plants with numbers p1 and p2 are connected. Each connection is described exactly once and there is at most one connection between every two plants.</p>

<p>The instances follow each other immediately, without any separator. The input is terminated by a line containing two zeros.</p>

### 출력 

 <p>The output consists of several lines. The i-th line of the output corresponds to the i-th input instance. Each line of the output consists of a single integer C. C is the maximum number of the connected parts of the network that can be obtained by removing one of the joining points at power plants in the instance.</p>

<p> </p>

