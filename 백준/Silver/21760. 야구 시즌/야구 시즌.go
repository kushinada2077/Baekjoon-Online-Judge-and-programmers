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

func calculate(n, m, a, b int64) int64 {
	in := n * m * (m - 1) / 2 * a
	out := n * m * (n*m - m) / 2 * b

	return in + out
}

func solve() {
	var n, m, k, d int64
	fmt.Fscan(reader, &n, &m, &k, &d)

	l := int64(-1)
	r := int64(2e9)

	for l+1 < r {
		mid := (l + r) / 2
		sum := calculate(n, m, k*mid, mid)
		if sum > d {
			r = mid
		} else {
			l = mid
		}
	}

	if l < 1 {
		fmt.Fprintln(writer, -1)
	} else {
		fmt.Fprintln(writer, calculate(n, m, k*l, l))
	}
}

func main() {
	defer writer.Flush()
	var t int
	fmt.Fscan(reader, &t)
	for ; t > 0; t-- {
		solve()
	}
}