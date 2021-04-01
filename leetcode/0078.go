package leetcode

func subsets(nums []int) (ans [][]int) {
	n := len(nums)
	ans, tmp := make([][]int, 0), make([]int, 0)
	var dfs func(int)
	dfs = func(lens int) {
		ans = append(ans, append([]int{}, tmp...))
		if lens == n {
			return
		}
		for j := lens; j < n; j++ {
			tmp = append(tmp, nums[j])
			dfs(j + 1)
			tmp = tmp[:len(tmp)-1]
		}
	}
	dfs(0)
	return
}

func subsets1(nums []int) (ans [][]int) {
    n := len(nums)
    for mask := 0; mask < 1<<n; mask++ {
        tmp := make([]int,0)
        for i := 0; i < n; i++ {
            if ((mask >> i)&1) > 0 {
                tmp = append(tmp,nums[i])
            }
        }
        ans = append(ans,tmp)
    }
    return
}

func subsets2(nums []int) (ans [][]int) {
    //n := len(nums)
    ans = append(ans,[]int{})
    for _,num := range nums {
        ansNum := len(ans)
        for i := 0; i < ansNum;i++ {
            tmp := append([]int{},ans[i]...)
            tmp = append(tmp,num)
            ans = append(ans,tmp)
        }
    }
    return
}
func subsets3(nums []int) (ans [][]int) {
    set := []int{}
    var dfs func(int)
    dfs = func(cur int) {
        if cur == len(nums) {
            ans = append(ans, append([]int(nil), set...))
            return
        }
        set = append(set, nums[cur])
        dfs(cur + 1)
        set = set[:len(set)-1]
        dfs(cur + 1)
    }
    dfs(0)
    return
}