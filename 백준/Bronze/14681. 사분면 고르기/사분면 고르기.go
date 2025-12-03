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

	var x, y int
	fmt.Fscan(reader, &x, &y)
	if x > 0 && y > 0 {
		fmt.Println(1)
	} else if x < 0 && y > 0 {
		fmt.Println(2)
	} else if x < 0 && y < 0 {
		fmt.Println(3)
	} else {
		fmt.Println(4)
	}
}