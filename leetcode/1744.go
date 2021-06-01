package leetcode

func canEat(candiesCount []int, queries [][]int) []bool {
	n := len(candiesCount)
	for i := 1; i < n; i++ {
		candiesCount[i] += candiesCount[i-1]
	}
	ans := make([]bool, 0)
	for _, query := range queries {
		t, d, c := query[0], query[1], query[2]
		cand_min, cand_max := d+1, (d+1)*c
		type_min, type_max := 1, candiesCount[t]
		if t > 0 {
			type_min += candiesCount[t-1]
		}
		ans = append(ans, !(cand_max < type_min || type_max < cand_min))
	}
	return ans
}
