package leetcode

type Trie struct {
	isword bool
	child  []*Trie
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{false, make([]*Trie, 26)}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	cur := this
	for _, ch := range word {
		idx := ch - 'a'
		if cur.child[idx] == nil {
			cur.child[idx] = &Trie{false, make([]*Trie, 26)}
		}
		cur = cur.child[idx]
	}
	cur.isword = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	cur := this
	for _, ch := range word {
		idx := ch - 'a'
		if cur.child[idx] == nil {
			return false
		}
		cur = cur.child[idx]
	}
	return cur.isword
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	cur := this
	for _, ch := range prefix {
		idx := ch - 'a'
		if cur.child[idx] == nil {
			return false
		}
		cur = cur.child[idx]
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
