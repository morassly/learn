package main

import(
    "fmt"
    "strings"
)

func main(){
    str := "This is an example of a string"
    fmt.Println(strings.HasPrefix(str,"Th"))
}