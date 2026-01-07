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

var (
	n int
)

func nxt(idx, d int) int {
	ret := idx + d
	if ret == n {
		ret = 0
	}
	if ret == -1 {
		ret = n - 1
	}

	return ret
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}

	return x
}

func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &n)
	arr := make([]int, n)
	chk := make([]bool, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}
	idx := 0

	for i := 0; i < n; i++ {
		chk[idx] = true
		fmt.Fprint(writer, idx+1, " ")
		x := arr[idx]
		d := 1
		if arr[idx] < 0 {
			d = -1
		}

		if i == n-1 {
			break
		}

		for j := 0; j < abs(x); {
			idx = nxt(idx, d)
			if chk[idx] == false {
				j++
			}
		}
	}
}