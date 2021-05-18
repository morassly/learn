package leetcode

func countTriplets(arr []int) int {
	n, ans, s := len(arr), 0, 0
	cnt, tot := make(map[int]int), make(map[int]int)

	for k := 0; k < n; k++ {
		val := s ^ arr[k]
		if _, ok := cnt[val]; ok {
			ans += cnt[val]*k - tot[val]
		}
		cnt[s]++
		tot[s] += k
		s = val
	}
	return ans
}
