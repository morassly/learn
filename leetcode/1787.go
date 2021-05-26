package leetcode

const (
	INF = 0x3f3f3f3f
	N   = 1024
)

func minChanges(nums []int, k int) int {

}
func min(i, j int) int {
	if i > j {
		return j
	}
	return i
}
func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
