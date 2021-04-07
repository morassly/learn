package leetcode

func permute(nums []int) (ans[][]int) {
    n := len(nums)
    var dfs func(int)
    dfs = func(i int){
        if i == n {
            ans = append(ans,append([]int{},nums...))
            return
        }
        for j := i; j < n; j++ {
            nums[i],nums[j] = nums[j],nums[i]
            dfs(i+1)
            nums[i],nums[j] = nums[j],nums[i]
        }
    }
    dfs(0)
    return
}