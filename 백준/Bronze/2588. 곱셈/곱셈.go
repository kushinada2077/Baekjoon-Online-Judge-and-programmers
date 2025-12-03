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

	var a, b int
	fmt.Fscan(reader, &a, &b)
	res := a * b
	for b > 0 {
		fmt.Println(a * (b % 10))
		b /= 10
	}
	fmt.Println(res)
}