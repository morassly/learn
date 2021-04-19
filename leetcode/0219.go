package leetcode

func containsNearbyDuplicate(nums []int, k int) bool {
	s := map[int]bool{}
	for i, _ := range nums {
		if c := s[nums[i]]; c {
			return true
		}
		s[nums[i]] = true
		if i >= k {
			s[nums[i-k]] = false
		}
	}
	return false
}
