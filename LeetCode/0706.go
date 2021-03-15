package leetcode

var cap int= 20009
type node struct{
	key,val int
	next *node
}


 type MyHashMap struct {
	data []*node
}


/** Initialize your data structure here. */
func Constructor() MyHashMap {
	return MyHashMap{
		make([]*node,cap),
	}
}


/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int)  {
	h := key % cap
	cur := this.data[h]
	var pre *node 
	for cur != nil{
		if cur.key == key{
			cur.val = value
			return 
		}else{
			pre = cur
			cur = cur.next
		}
	}
	cur = &node{key,value,nil}

	if pre != nil{
		pre.next = cur
	}else{
		this.data[h] = cur
	}
}


/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	h := key % cap
	cur := this.data[h]
	for cur != nil{
		if cur.key == key{
			return cur.val
		}else{
			cur = cur.next
		}
	}
	return -1
}


/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int)  {
	h := key % cap
	cur := this.data[h]
	var pre *node
	for cur != nil{
		if cur.key == key{
			if pre == nil{
				this.data[h] = cur.next
			}else{
				pre.next = cur.next
			}
			return
		}else{
			pre = cur
			cur = cur.next
		}
	}
	return
}




package main

import "fmt"

type student struct {
	name string
	age  int
}

func main() {
	m := make(map[string]*student)
	stus := []student{
		{name: "小王子", age: 18},
		{name: "娜扎", age: 23},
		{name: "大王八", age: 9000},
	}
    
	for i, stu := range stus {
		m[stu.name] = &stus[i]
        fmt.Println(m[stu.name])
	}
	for k, v := range m {
		fmt.Println(k, "=>", v.name)
	}
}
type MyHashMap11 struct {
    data []list.List
}
type node1 struct{
    key, val int
}

/** Initialize your data structure here. */
func Constructor1() MyHashMap1 {
    return MyHashMap1{
        make([]list.List,1009),
    }
}
func (m *MyHashMap1) hash1(key int) int {
    return key % 1009
}

/** value will always be non-negative. */
func (m *MyHashMap1) Put1(key int, value int)  {
    h := m.hash1(key)
    for e := m.data[h].Front(); e != nil; e = e.Next() {
        if et := e.Value.(node1); et.key == key {
            e.Value = node1{key, value}
            return
        }
    }
    m.data[h].PushBack(node1{key, value})
}


/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (m *MyHashMap1) Get1(key int) int {
    h := m.hash1(key)
    for e := m.data[h].Front(); e != nil; e = e.Next() {
        if et := e.Value.(node1); et.key == key {
            return et.val
        }
    }
    return -1
}


/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (m *MyHashMap1) Remove1(key int)  {
    h := m.hash1(key)
    for e := m.data[h].Front(); e != nil; e = e.Next() {
        if e.Value.(node1).key == key {
            m.data[h].Remove(e)
        }
    }
}


/**
 * Your MyHashMap1 object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */