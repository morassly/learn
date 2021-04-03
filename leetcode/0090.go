package leetcode

import "sort"

func subsetsWithDup(nums []int) [][]int {
	ans, tmp, n := make([][]int, 0), make([]int, 0), len(nums)
	sort.Ints(nums)
	var dfs func(int)
	dfs = func(lens int) {
		ans = append(ans, append([]int{}, tmp...))
		if lens == n {
			return
		}
		for j := lens; j < n; j++ {
			if j > lens && nums[j] == nums[j-1] {
				continue
			}
			tmp = append(tmp, nums[j])
			dfs(j + 1)
			tmp = tmp[:len(tmp)-1]
		}
	}
	dfs(0)
	return ans
}
