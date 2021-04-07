package leetcode

func permuteUnique(nums []int) (ans [][]int) {
	n := len(nums)
	sort.Ints(nums)
	vis, tmp := make([]bool, n), make([]int, 0)
	var dfs func(int)
	dfs = func(i int) {
		if i == n {
			ans = append(ans, append([]int{}, tmp...))
			return
		}
		for j := 0; j < n; j++ {
			if vis[j] || (j > 0 && nums[j] == nums[j-1] && !vis[j-1]) {
				continue
			}
			vis[j], tmp = true, append(tmp, nums[j])
			dfs(i + 1)
			vis[j], tmp = false, tmp[:len(tmp)-1]
		}
	}
	dfs(0)
	return
}
