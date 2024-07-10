# [Silver III] 거북이 - 8911 

[문제 링크](https://www.acmicpc.net/problem/8911) 

### 성능 요약

메모리: 2024 KB, 시간: 36 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2024년 7월 10일 16:34:58

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images/turtle2(1).png" style="float:right; height:139px; width:183px">You have a turtle robot moving in the two-dimensional Cartesian plane. The movement of this robot is determined by a sequence of the following commands:</p>

<ol>
	<li>F: move forward just one unit</li>
	<li>B: move backward just one unit</li>
	<li>L: turn left 90 degree</li>
	<li>R: turn right 90 degree</li>
</ol>

<p>The last two commands, L and R, only change the orientation of the robot without changing its location. We will call the sequence of commands the control program of the turtle robot. </p>

<p>You are to determine and estimate a portion of the plane that is large enough for the turtle s movement for a given control program. To make the problem simple, the portion is assumed to be a box whose edges are parallel to either the x- or y- axis of the Cartesian plane. More specifically, your program should calculate the size of the minimal bounding box which is large enough to encompass the trace of the movements of the turtle for a given control program.</p>

<p>Let s think of an example. You may assume that the turtle is initially at the origin (0, 0) facing to the north, without loss of generality. If the control program is given as FLFRFLBRBLB, the turtle will move on the following track of the Cartesian plane:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/turtle.png" style="height:294px; width:304px"></p>

<p>Note that the dotted portion of the track denotes backward movement. As shown in the picture, the 2 2 gray box is enough to encompass the movement of the turtle. Therefore, your program should write 4, since the width and the height of the bounding box are both 2.</p>

<p>Note that the trace of the turtle may not form a box in some cases. For instance, if the control program is given by FFLLFF, the turtle moves only on the y-axis. Therefore, the bounding box is not practically a box but a line segment, which implies that the width of the bounding box is zero. You program should output zero in such cases.</p>

### 입력 

 <p>Your program is to read the input from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case consists of a character string where each character denotes the control command. The string is given in a single line and consists only of four commands of the turtle robot. The length of the string is greater than 0 and no more than 500.</p>

### 출력 

 <p>Your program is to write to standard output. Print the area of the bounding box as a decimal integer in a single line for each test case.</p>

