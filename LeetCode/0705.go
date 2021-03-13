package leetcode

type MyHashSet struct {
	data []bool
}

/** Initialize your data structure here. */
func Constructor() MyHashSet {
	return MyHashSet{
		make([]bool, 1000001),
	}
}

func (this *MyHashSet) Add(key int) {
	this.data[key] = true
}

func (this *MyHashSet) Remove(key int) {
	this.data[key] = false
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
	return this.data[key]
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */

type MyHashSet1 struct {
	data [40000]int
}

/** Initialize your data structure here. */
func Constructor1() MyHashSet {
	return MyHashSet1{
		[40000]int{},
	}
}

func (this *MyHashSet1) setval(a, b int, flag bool) {
	if flag {
		this.data[a] = this.data[a] | (1 << b)
	} else {
		this.data[a] = this.data[a] & ^(1 << b)
	}
}

func (this *MyHashSet1) Add1(key int) {
	this.setval(key/32, key%32, true)
}

func (this *MyHashSet1) Remove1(key int) {
	this.setval(key/32, key%32, false)
}

func (this *MyHashSet1) getval(a, b int) bool {
	return (this.data[a]>>b)&1 == 1
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet1) Contains1(key int) bool {
	return this.getval(key/32, key%32)
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
