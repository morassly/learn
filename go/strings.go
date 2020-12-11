package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	str := "This is an example of a string"
	fmt.Println(strings.HasPrefix(str, "Th"))
	fmt.Println(strings.Contains(str, "an"))
	fmt.Println(strings.Index(str, "a"))
	fmt.Println(strings.LastIndex(str, "a"))
	fmt.Println(strings.IndexByte(str, 'a'))
	fmt.Println(strings.Count(str, "a"))
	str1 := fmt.Sprintf("%s \n", strings.Repeat("hello ", 3))
	fmt.Printf("%s \n", strings.ToUpper(str1))
	strReader := strings.NewReader(str)
	newStr := make([]byte, 8)
	strReader.Read(newStr)
	fmt.Printf("%s\n", newStr)
	fmt.Printf("%s %s \n", strconv.Itoa(12), strconv.FormatFloat(2.0, 'f', 1, 64))
}
