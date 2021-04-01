package leetcode

func combinationSum(candidates []int, target int) (ans [][]int) {
	comb := []int{}
	var dfs func(target, idx int)
	dfs = func(target, idx int) {
		if target == 0 {
			ans = append(ans, append([]int{}, comb...))
			return
		}
		if idx >= len(candidates) {
			return
		}
		dfs(target, idx+1)
		if target >= candidates[idx] {
			comb = append(comb, candidates[idx])
			dfs(target-candidates[idx], idx)
			comb = comb[:len(comb)-1]
		}
	}
	dfs(target, 0)
	return
}

func combinationSum1(candidates []int, target int) (ans [][]int) {
	comb := []int{}
	var dfs func(target, idx int)
	//idx 表示从此处选
	dfs = func(target, idx int) {
        if target == 0 {
            ans = append(ans,append([]int{},comb...))
            return
        }
        for i := idx; i < len(candidates)&&target >= candidates[idx];i++ {
            comb = append(comb,candidates[i])
            dfs(target-candidates[i],i)
            comb = comb[:len(comb)-1]
        }
	}
    sort.Ints(candidates)
	dfs(target, 0)
	return
}