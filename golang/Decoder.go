package main

import (
	"fmt"
	"os"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

const FirstSymbol = uint64(20000)

func main() {
	f, err := os.Open("../picture.bmp")
	check(err)

	defer func(f *os.File) {
		err := f.Close()
		check(err)
	}(f)

	b1 := make([]byte, 1)
	position := FirstSymbol

	for true {
		n1, err := f.ReadAt(b1, int64(position))

		check(err)

		result := string(b1[:n1])

		// A single 0 byte marks the end of the message
		if b1[0] != 0 {
			fmt.Printf(result)

			b2 := make([]byte, 3)

			_, err := f.ReadAt(b2, int64(position+1))

			check(err)

			position = uint64(b2[0]) | uint64(b2[1])<<8 | uint64(b2[2])<<16

			continue
		}

		break
	}
}
