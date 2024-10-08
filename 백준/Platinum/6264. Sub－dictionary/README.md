# [Platinum I] Sub-dictionary - 6264 

[문제 링크](https://www.acmicpc.net/problem/6264) 

### 성능 요약

메모리: 11516 KB, 시간: 0 ms

### 분류

방향 비순환 그래프, 그래프 이론, 강한 연결 요소, 위상 정렬

### 제출 일자

2024년 10월 3일 15:24:36

### 문제 설명

<p>In this problem, by the word "dictionary" we mean a list of alphabetically ordered words and their associated explanations in the same language. A dictionary must contain the definition for any word that appears in the explanation of another word. So you see, if a dictionary defines N words, it has exactly N distinct words in it. Also, we know that in a dictionary no word appears in the definition of itself.</p>

<p>A sub-dictionary is a collection of dictionary's words and their definitions such that it can be published as an independent dictionary, obviously satisfying the mentioned condition. As a project of Computational Linguistics course, we are assigned to create a Lexical Knowledge Base which is the knowledge expressed by words. For this task we should create our knowledge foundation based on a dictionary.</p>

<p>It's really hard for the computer to study words automatically. So, we decided to manually teach it some common words. We start from an appropriate sub-dictionary. By understanding its words, a computer could extend its knowledge to the whole dictionary word by word. For instance, a word "xyz" could be added to the computer's understanding if computer knows the meaning of every words used in xyz's definition. You are asked to write a program that can find the smallest extendable sub-dictionary for a specific dictionary</p>

### 입력 

 <p>The input consists of multiple test cases. The first line of each test case is n (1 ≤ n ≤ 100), the number of dictionary's words. Each of the next n lines contains a word and its definition (that has at most 30 words). Words are separated by blanks and are made up of small English letters less than 25 characters.</p>

### 출력 

 <p>For each test case, on the first line print the number of sub-dictionary's words and on the second line write the alphabetically sorted list of words (separated by blanks).</p>

