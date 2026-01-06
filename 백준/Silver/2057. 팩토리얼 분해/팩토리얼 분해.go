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
	MAX int64  = 20
	ans string = "NO"
	n   int64
	fac [21]int64
)

func f(k, sum int64) {
	if k == MAX {
		if sum == n {
			ans = "YES"
		}
		return
	}

	f(k+1, sum)
	f(k+1, sum+fac[k])
}
func main() {
	defer writer.Flush()
	fmt.Fscan(reader, &n)
	if n == 0 {
		n = -1
	}

	fac[0] = 1
	for i := int64(1); i <= 20; i++ {
		fac[i] = fac[i-1] * i
	}

	f(0, 0)
	fmt.Fprintln(writer, ans)
}