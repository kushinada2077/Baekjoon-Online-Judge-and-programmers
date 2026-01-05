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

	var p int
	fmt.Fscan(reader, &p)

	for ; p > 0; p-- {
		var n, m int
		fmt.Fscan(reader, &n, &m)
		cnt := 1
		p1 := 1
		p2 := 1

		for ; ; cnt++ {
			if p1 == 0 && p2 == 1 {
				break
			}
			tmp := p1
			p1 = p2
			p2 = (tmp + p2) % m
		}

		fmt.Fprint(writer, n, " ", cnt, "\n")
	}
}