package leetcode

func isPalindrome(x int) bool {
    if x < 0 || (x % 10 == 0 && x != 0){
        return false
    }
        
    ans := 0
    for x > ans{
        ans = ans*10 + x%10
        x /= 10
    }
    return x == ans || x == ans/10
}