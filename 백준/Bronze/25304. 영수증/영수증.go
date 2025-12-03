package main

import (
	"bufio"
	"fmt"
	"os"
)

const PATH = "/Users/leedongha/Downloads/PS/input.txt"

func init() {
	if file, err := os.Open(PATH); err == nil {
		os.Stdin = file
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, x int
	fmt.Fscan(reader, &x, &n)
	sum := 0
	for ; n > 0; n-- {
		var a, b int
		fmt.Fscan(reader, &a, &b)
		sum += a * b
	}

	if x == sum {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}