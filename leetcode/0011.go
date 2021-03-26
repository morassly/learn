package leetcode

func maxArea(height []int) int {
	i, j := 0, len(height)-1
	ans := 0
	maxmin := func(i, j, f int) int {
		if f > 0 {
			if i > j {
				return i
			}
			return j
		} else {
			if i > j {
				return j
			}
			return i
		}
	}
	for i < j {
		tmp := (j - i) * maxmin(height[i], height[j], 0)
		ans = maxmin(ans, tmp, 1)
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return ans
}
