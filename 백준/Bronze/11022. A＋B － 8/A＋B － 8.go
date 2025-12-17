package main

import (
	"bufio"
	"fmt"
	"os"
)

func init() {
	path := os.Getenv("MY_PATH")
	if file, err := os.Open(path); err == nil {
		os.Stdin = file
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		fmt.Printf("Case #%d: %d + %d = %d\n", i+1, a, b, a+b)
	}
}