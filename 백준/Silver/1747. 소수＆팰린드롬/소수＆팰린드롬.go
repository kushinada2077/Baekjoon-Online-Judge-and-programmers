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

func isPrime(n int) bool {
	if n == 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func isPal(n int) bool {
	new_n := 0

	for copy_n := n; copy_n > 0; {
		new_n = 10*new_n + copy_n%10
		copy_n /= 10
	}

	return n == new_n
}

func main() {
	defer writer.Flush()
	var n int
	fmt.Fscan(reader, &n)

	for i := n; ; i++ {
		if isPrime(i) && isPal(i) {
			fmt.Fprintln(writer, i)
			break
		}
	}
}