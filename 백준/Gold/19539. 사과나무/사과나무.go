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

func main() {
	defer writer.Flush()
	var n int
	fmt.Fscan(reader, &n)
	cnt_two := 0
	sum := 0

	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(reader, &x)
		if x == 0 {
			continue
		}
		sum += x
		cnt_two += x / 2
	}

	var ans string
	if sum%3 != 0 || cnt_two < sum/3 {
		ans = "NO"
	} else {
		ans = "YES"
	}

	fmt.Fprintln(writer, ans)
}