package leetcode

import "sort"

func threeSumClosest(nums []int, target int) int {
	ans, n := nums[0]+nums[1]+nums[2], len(nums)
	if n == 3 {
		return ans
	}
	sort.Ints(nums)
	abs := func(i int) int {
		if i < 0 {
			return -i
		}
		return i
	}
	for i := 0; i < n-2; i++ {
		if i == 0 || nums[i] != nums[i-1] {
			l, r := i+1, n-1
			for l < r {
				if abs(ans-target) > abs(nums[i]+nums[l]+nums[r]-target) {
					ans = nums[i] + nums[l] + nums[r]
				}
				if nums[i]+nums[l]+nums[r] < target {
					l++
				} else if nums[i]+nums[l]+nums[r] > target {
					r--
				} else {
					return target
				}
			}
		}
	}
	return ans
}
