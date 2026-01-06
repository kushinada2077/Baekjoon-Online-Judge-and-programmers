package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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
	var s string
	fmt.Fscan(reader, &s)
	num_a := strings.Count(s, "a")
	ans := 2000

	for i := 0; i < len(s); i++ {
		cnt := 0
		for j := 0; j < num_a; j++ {
			if s[(i+j)%len(s)] == 'b' {
				cnt++
			}
		}

		ans = min(ans, cnt)
	}

	fmt.Fprintln(writer, ans)
}