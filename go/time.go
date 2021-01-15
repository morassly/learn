package main

import (
	"fmt"
	"time"
)

var week time.Duration

func main() {
	t := time.Now()
	fmt.Println(t) // 2020-12-11 15:11:07.249172 +0800 CST m=+0.000115931
	fmt.Printf("%02d.%02d.%4d\n", t.Day(), t.Month(), t.Year())
	// 11.12.2020
	t = time.Now().UTC()
	fmt.Println(t)          // 2020-12-11 07:11:07.249322 +0000 UTC
	fmt.Println(time.Now()) // 2020-12-11 15:11:07.249325 +0800 CST m=+0.000269145
	// calculating times:
	week = 60 * 60 * 24 * 7 * 1e9 // must be in nanosec
	weekFromNow := t.Add(time.Duration(week))
	fmt.Println(weekFromNow) // 2020-12-18 07:11:07.249322 +0000 UTC
	// formatting times:
	fmt.Println(t.Format(time.RFC822)) // 11 Dec 20 07:11 UTC
	fmt.Println(t.Format(time.ANSIC))  // Fri Dec 11 07:11:07 2020
	// The time must be 2006-01-02 15:04:05
	fmt.Println(t.Format("02 Jan 2006 15:04")) //11 Dec 2020 07:11
	s := t.Format("20060102")
	fmt.Println(t, "=>", s)
	// 2020-12-11 07:11:07.249322 +0000 UTC => 20201211
	timeAfter := <-time.After(time.Second)
	fmt.Println(timeAfter)
}
