# 最长问题 #
- [最长问题](#最长问题)
  - [最长公共子序列LCS](#最长公共子序列lcs)
    - [1.递推公式](#1递推公式)
    - [2. 实现细节](#2-实现细节)
    - [3.模版](#3模版)
  - [最长公共子串](#最长公共子串)
    - [1.递推公式](#1递推公式-1)
  - [最长回文子序列LPS（Longest Palindromic Subsequence）](#最长回文子序列lpslongest-palindromic-subsequence)
    - [1.递推公式](#1递推公式-2)
    - [2.实现细节](#2实现细节)
    - [3.模版](#3模版-1)
  - [最长回文子串](#最长回文子串)
    - [dp模版](#dp模版)
    - [3.manacher 模版](#3manacher-模版)
  - [最长递增子序列](#最长递增子序列)
## 最长公共子序列LCS ##
### 1.递推公式 ###
$dp[i][j]表示S1[0...i-1]与S2[0...j-1]的最长公共子序列$
$$ dp[i][j]=\left\{
\begin{aligned}
&0 &i==0 \quad or \quad j==0\\
&dp[i-1][j-1] + 1 &S1[i-1]==S2[j-1] \\
&max(dp[i-1][j],dp[i][j-1])& others \\
\end{aligned}
\right.
$$
### 2. 实现细节
可以用二维数组滚动压缩空间
### 3.模版
```c++
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(),n = text2.size();
    int dp[2][n+1];
    fill(dp[0],dp[0]+n+1,0);
    fill(dp[1],dp[1]+n+1,0);
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            if (text1[i] == text2[j]) {
                dp[(i+1)&1][j+1] = dp[i&1][j] + 1;
            } else {
                dp[(i+1)&1][j+1] = max(dp[(i+1)&1][j],dp[i&1][j+1]);
            }
        }
    }
    return dp[m&1][n];
}
```
```go
func longestCommonSubsequence(text1 string, text2 string) int {
    // if len(text1) < len(text2) {
    //     text1, text2 = text2, text1
    // }
    m,n := len(text1), len(text2)
    ans := make([][]int,2)
    for i := 0 ;i < 2; i++ {
        ans[i] = make([]int,n+1)
    }
    for i, ch1 := range text1 {
        for j, ch2 := range text2 {
            if ch1 == ch2 {
                ans[(i+1)&1][j + 1] = ans[i&1][j] + 1
            } else if ans[i&1][j+1] < ans[(i+1)&1][j] {
                ans[(i+1)&1][j+1] = ans[(i+1)&1][j]
            }else {
                ans[(i+1)&1][j+1] = ans[i&1][j+1]
            }
        }
    }
    return ans[m&1][n]
}
```
## 最长公共子串 ##
### 1.递推公式 ###
$dp[i][j]表示S1[0...i-1]与S2[0...j-1]的最长公共子串$
$$ dp[i][j]=\left\{
\begin{aligned}
&0 &i==0 \quad or \quad j==0\\
&dp[i-1][j-1] + 1 &S1[i-1]==S2[j-1] \\
&0& others \\
\end{aligned}
\right.
$$
## 最长回文子序列LPS（Longest Palindromic Subsequence） ##
### 1.递推公式 ###
$S[0...n-1]是给定的字符串序列，长度为n，假设dp[0][n-1]表示序列S[0...n-1]的最长回文子序列的长度$
$$ dp[i][j]=\left\{
\begin{aligned}
&1 &i==j \\
&0 & i > j \\
&dp[i+1][j-1] + 2 &S[i]==S[j] \\
&max(dp[i][j-1],dp[i+1][j])& others \\
\end{aligned}
\right.
$$
### 2.实现细节
$i$倒叙遍历才能保证正确性
### 3.模版
```c++
int dp[1001][1001];
int longestPalindromeSubseq(string s) {
    int n = s.size();
    for (auto i = n-1; i >= 0; i--) {
        dp[i][i] = 1;
        for (auto j = i+1;j < n; j++){
            if (s[i]==s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j]= max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}
```
```go
package leetcode

func longestPalindromeSubseq(s string) int {
	n := len(s)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for i := n - 1; i >= 0; i-- {
		dp[i][i] = 1
		for j := i + 1; j < n; j++ {
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else if dp[i][j-1] > dp[i+1][j] {
				dp[i][j] = dp[i][j-1]
			} else {
				dp[i][j] = dp[i+1][j]
			}
		}
	}
	return dp[0][n-1]
}

```
## 最长回文子串 ##
### dp模版 ###
### 3.manacher 模版 ###
```go
package leetcode

func longestPalindrome(s string) string {
	if len(s) < 2 {
		return s
	}

	str := make([]rune, 0)
	str = append(str, '@')
	str = append(str, '#')
	for _, i := range s {
		str = append(str, i)
		str = append(str, '#')
	}
	str = append(str, '$')
	dp, center, right, maxlen, left := make([]int, len(str)), 0, 0, 0, 0
	for i := 1; i < len(str)-1; i++ {
		if i < right {
			dp[i] = min(right-i, dp[center*2-i])
		}
		for str[i+1+dp[i]] == str[i-dp[i]-1] {
			dp[i]++
		}
		if i+dp[i] > right {
			center = i
			right = i + dp[i]
		}
		if dp[i] > maxlen {
			maxlen = dp[i]
			left = (i - dp[i]) >> 1
		}
	}
	return s[left : left+maxlen]
}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

```
## 最长递增子序列