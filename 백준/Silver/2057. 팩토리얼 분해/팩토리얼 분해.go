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
	var n int64
	fmt.Fscan(reader, &n)
	if n == 0 {
		n = -1
	}
	var fac int64 = 1

	for i := int64(2); i <= 20; i++ {
		fac *= i
	}

	for i := int64(20); i > 0; i-- {
		if n >= fac {
			n -= fac
		}
		fac /= i
	}

	if n == 1 {
		n -= 1
	}

	if n == 0 {
		fmt.Fprintln(writer, "YES")
	} else {
		fmt.Fprintln(writer, "NO")
	}
}