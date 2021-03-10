package leetcode

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums2) < len(nums1) {
		return findMedianSortedArrays(nums2, nums1)
	}

	left, right, tol, mid1, mid2 := 0, len(nums1)+1, len(nums1)+len(nums2)+1, 0, 0
	median1, median2 := 0, 0
	for left < right {
		mid1 = left + (right-left)>>1
		mid2 = tol>>1 - mid1

		min1 := math.MinInt32
		if mid1 != 0 {
			min1 = nums1[mid1-1]
		}

		max1 := math.MaxInt32
		if mid1 != len(nums1) {
			max1 = nums1[mid1]
		}

		min2 := math.MinInt32
		if mid2 != 0 {
			min2 = nums2[mid2-1]
		}

		max2 := math.MaxInt32
		if mid2 != len(nums2) {
			max2 = nums2[mid2]
		}

		if min1 <= max2 {
			median1 = max(min1, min2)
			median2 = min(max1, max2)
			left = mid1 + 1
		} else {
			right = mid1
		}
	}
	if (len(nums1)+len(nums2))%2 == 0 {
		return float64(median1+median2) / 2.0
	}
	return float64(median1)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
