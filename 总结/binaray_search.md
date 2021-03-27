
# 二分总结 #
- [二分总结](#二分总结)
	- [写法](#写法)
		- [C++实现](#c实现)
		- [Go实现](#go实现)
	- [leetcode题号](#leetcode题号)
## 写法 ##
### C++实现 ###
```c++
//查找值
//a[]升序，相当于lower_bound(a,a+n)
//搜索区间 [0,n-1]
int binaray_search(int &a[],int key, int l, int r) {
	int mid = l + ((r - l) >> 1);//决定区间即 [l,mid],[mid,r)
	while (l <= r) {
        //if (a[mid] < key) l = mid+1; 相当于upper_bound(a,a+n)
        if (a[mid] == key) return mid;
		else if (a[mid] < key) l = mid+1;
		else r = mid - 1;

	}
	return l;//此时 l==r
}
//a[]升序，相当于lower_bound(a,a+n)
//搜索区间 [0,n)
int binaray_search(int &a[],int key, int l, int r) {
	int mid = l + ((r - l) >> 1);//决定区间即 [l,mid],[mid,r)
	while (l < r) {
        //if (a[mid] < key) l = mid+1; 相当于upper_bound(a,a+n)
		if (a[mid] < key) l = mid+1;
		else r = mid;

	}
	return l;//此时 l==r
}

//a[]降序，相当于lower_bound(a,a+n,greater<int>())
//搜索区间 [0,n)
int binaray_search(int &a[],int key, int l, int r) {
	int mid = l + ((r - l) >> 1);//决定区间即 [l,mid],[mid,r)
	while (l < r) {
        //if (a[mid] >= key) l = mid+1; 相当于upper_bound(a,a+n,greater<int>())
		if (a[mid] > key) l = mid+1;
		else r = mid;

	}
	return l;//此时 l==r
}
```

### Go实现 ###
```golang
//a 升序，相当于lower_bound(a,a+n)
//搜索区间 [0,n)
//sort.Search(len(a),func(i int){return a[i] >= key})
func binary(a []int, key int) int {
	l, r := 0, len(a)

	for l < r {
		mid := l + (r-l)/2
		if a[mid] < x {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}
//a 升序，相当于upper_bound(a,a+n)
//sort.Search(len(a),func(i int){return a[i] > key})

//a[]降序，相当于lower_bound(a,a+n,greater<int>())
//sort.Search(len(a),func(i int){return a[i] <= key})


//相当于upper_bound(a,a+n,greater<int>())
//sort.Search(len(a),func(i int){return a[i] < key})
```

## leetcode题号 ##

1. 0004 [CPP](../leetcode/0004.cpp) [GO](../leetcode/0004.go)
2. 0033 [CPP](../leetcode/0033.cpp) [GO](../leetcode/0033.go)
3. 0034 [CPP](../leetcode/0034.cpp) [GO](../leetcode/0034.go)
4. 0035 [CPP](../leetcode/0035.cpp) [GO](../leetcode/0035.go)