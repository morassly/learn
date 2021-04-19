package leetcode

func containsDuplicate(nums []int) bool {
	s := map[int]int{}
	for _, i := range nums {
		if _, ok := s[i]; ok {
			return true
		}
		s[i] = 1
	}
	return false
}
