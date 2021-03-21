package leetcode

import "sort"

func threeSum(nums []int) [][]int {
	ans, n := make([][]int, 0), len(nums)
	sort.Ints(nums)

	for i := 0; i < n-2; i++ {
		if nums[i] > 0 {
			return ans
		}
		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		l, r := i+1, n-1
		for l < r {
			if nums[i]+nums[l]+nums[r] < 0 {
				l++
			} else if nums[i]+nums[l]+nums[r] > 0 {
				r--
			} else {
				ans = append(ans, []int{nums[i], nums[l], nums[r]})
				for l < r && nums[l] == nums[l+1] {
					l++
				}
				for l < r && nums[r] == nums[r-1] {
					r--
				}
				l++
				r--
			}
		}
	}
	return ans
}
