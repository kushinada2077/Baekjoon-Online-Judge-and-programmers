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

	var n int
	fmt.Fscan(reader, &n)
	for ; n > 0; n -= 4 {
		fmt.Print("long ")
	}
	fmt.Print("int")
}