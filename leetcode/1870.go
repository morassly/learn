package leetcode

import (
	"math"
	"sort"
)

func minSpeedOnTime(dist []int, hour float64) int {
	h100 := int(math.Round(hour * 100))
	n := len(dist)
	if h100 <= (n-1)*100 {
		return -1
	}
	return 1 + sort.Search(1e7-1, func(v int) bool {
		v++
		h := 0
		for _, d := range dist[:n-1] {
			h += (d - 1 + v) / v
		}
		return (h*v+dist[n-1])*100 <= h100*v
	})
}
