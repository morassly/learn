package leetcode

func trap(height []int) int {
	l, lm, r, rm := 0, 0, len(height)-1, 0
	ans := 0
	for l < r {
		if height[l] < height[r] {
			if height[l] >= lm {
				lm = height[l]
			} else {
				ans += (lm - height[l])
			}
			l++
		} else {
			if height[r] >= rm {
				rm = height[r]
			} else {
				ans += (rm - height[r])
			}
			r--
		}
	}
	return ans
}
