package leetcode

func longestCommonPrefix(strs []string) string {
    if len(strs) == 0{
        return ""
    }
    minstr, maxstr := strs[0],strs[0]
    for _,s := range strs{
        if s < minstr{
            minstr = s
        }
        if s > maxstr{
            maxstr = s
        }
    }
    i := 0
    for ; i < len(minstr)&&minstr[i]==maxstr[i];i++{
    }

    return minstr[:i]
}