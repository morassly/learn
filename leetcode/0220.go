package leetcode

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	m, n := map[int]int{}, len(nums)
	getId := func(x, w int) int {
		if x < 0 {
			return (x+1)/w - 1
		}
		return x / w
	}
	for i := 0; i < n; i++ {
		id := getId(nums[i], t+1)
		if _, ok := m[id]; ok {
			return true
		}
		if y, ok := m[id+1]; ok && y-nums[i] <= t {
			return true
		}
		if y, ok := m[id-1]; ok && nums[i]-y <= t {
			return true
		}
		m[id] = nums[i]
		if i >= k {
			delete(m, getId(nums[i-k], t+1))
		}
	}
	return false
}
