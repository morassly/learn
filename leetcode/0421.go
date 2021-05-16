package leetcode

const highBit = 30

type trie struct {
	left, right *trie
}

func (t *trie) add(num int) {
	cur := t
	for i := highBit; i >= 0; i-- {
		if bit := num >> i & 1; bit == 0 {
			if cur.left == nil {
				cur.left = &trie{}
			}
			cur = cur.left
		} else {
			if cur.right == nil {
				cur.right = &trie{}
			}
			cur = cur.right
		}
	}
}

func (t *trie) check(num int) (x int) {
	cur := t
	for i := highBit; i >= 0; i-- {
		if bit := num >> i & 1; bit == 0 {
			if cur.right != nil {
				cur = cur.right
				x = x*2 + 1
			} else {
				cur = cur.left
				x = x * 2
			}
		} else {
			if cur.left != nil {
				cur = cur.left
				x = x*2 + 1
			} else {
				cur = cur.right
				x = x * 2
			}
		}
	}
	return
}

func findMaximumXOR(nums []int) (x int) {
	root := &trie{}
	for i := 1; i < len(nums); i++ {
		root.add(nums[i-1])
		x = max(x, root.check(nums[i]))
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
