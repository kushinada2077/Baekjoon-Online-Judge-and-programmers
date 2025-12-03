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

	var a, b, c int
	fmt.Fscan(reader, &a, &b, &c)
	fmt.Println((a + b) % c)
	fmt.Println(((a % c) + (b % c)) % c)
	fmt.Println(a * b % c)
	fmt.Println((a % c) * (b % c) % c)
}