package leetcode

type FindSumPairs struct {
	nums1 []int
	nums2 []int
	uMap  map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	uMap := make(map[int]int, 0)
	for _, v2 := range nums2 {
		uMap[v2]++
	}
	return FindSumPairs{nums1: nums1, nums2: nums2, uMap: uMap}
}

func (this *FindSumPairs) Add(index int, val int) {
	this.uMap[this.nums2[index]]--
	this.nums2[index] += val
	this.uMap[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) int {
	res := 0
	for _, v := range this.nums1 {
		if n, ok := this.uMap[tot-v]; ok {
			res += n
		}
	}
	return res
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */
