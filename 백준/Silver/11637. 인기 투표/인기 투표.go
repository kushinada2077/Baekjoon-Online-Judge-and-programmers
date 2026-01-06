package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader *bufio.Reader
	writer *bufio.Writer
)

func init() {
	path := os.Getenv("MY_PATH")
	if file, err := os.Open(path); err == nil {
		os.Stdin = file
	}
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

func solve() {
	var n int
	fmt.Fscan(reader, &n)
	sum := 0
	idx := -1
	arr := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
		sum += arr[i]
		if idx == -1 || arr[idx] < arr[i] {
			idx = i
		}
	}

	cnt := 0
	for _, v := range arr {
		if v == arr[idx] {
			cnt++
		}
	}

	if cnt > 1 {
		fmt.Fprintln(writer, "no winner")
	} else {
		if 2*arr[idx] > sum {
			fmt.Fprint(writer, "majority winner ")
		} else {
			fmt.Fprint(writer, "minority winner ")
		}

		fmt.Fprintln(writer, idx+1)
	}
}

func main() {
	defer writer.Flush()
	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		solve()
	}
}