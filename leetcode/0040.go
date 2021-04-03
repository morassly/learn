package leetcode

import "sort"

func combinationSum2(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	tmp, n := []int{}, len(candidates)
	var dfs func(bool, int, int)
	dfs = func(is bool, idx, target int) {
		if target == 0 {
			ans = append(ans, append([]int{}, tmp...))
			return
		}
		if idx == n {
			return
		}
		dfs(false, idx+1, target)
		if idx > 0 && !is && candidates[idx] == candidates[idx-1] {
			return
		}
		if target >= candidates[idx] {
			tmp = append(tmp, candidates[idx])
			dfs(true, idx+1, target-candidates[idx])
			tmp = tmp[:len(tmp)-1]
		}
	}
	dfs(false, 0, target)
	return
}

func combinationSum22(candidates []int, target int) (ans [][]int) {
	sort.Ints(candidates)
	tmp, n := []int{}, len(candidates)
	var dfs func(int, int)
	dfs = func(idx, target int) {
		if target == 0 {
			ans = append(ans, append([]int{}, tmp...))
			return
		}
		if idx == n {
			return
		}
		for i := idx; i < n && target >= candidates[i]; i++ {
			if i > idx && candidates[i] == candidates[i-1] {
				continue
			}
			tmp = append(tmp, candidates[i])
			dfs(i+1, target-candidates[i])
			tmp = tmp[:len(tmp)-1]
		}
	}
	dfs(0, target)
	return
}
