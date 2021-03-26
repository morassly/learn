package leetcode

import "sort"

func fourSum(nums []int, target int) [][]int {
	ans, n := make([][]int, 0), len(nums)
	sort.Ints(nums)

	for i := 0; i < n-3 && nums[i]+nums[i+1]+nums[i+2]+nums[i+3] <= target; i++ {
		if i != 0 && nums[i] == nums[i-1] || nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target {
			continue
		}
		for j := i + 1; j < n-2 && nums[i]+nums[j]+nums[j+1]+nums[j+2] <= target; j++ {
			if j != i+1 && nums[j] == nums[j-1] || nums[i]+nums[j]+nums[n-1]+nums[n-2] < target {
				continue
			}
			l, r := j+1, n-1
			for l < r {
				if nums[i]+nums[j]+nums[l]+nums[r] < target {
					l++
				} else if nums[i]+nums[j]+nums[l]+nums[r] > target {
					r--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[l], nums[r]})
					for l++; l < r && nums[l] == nums[l-1]; l++ {
					}
					for r--; l < r && nums[r] == nums[r+1]; r-- {
					}
				}
			}
		}
	}
	return ans
}
