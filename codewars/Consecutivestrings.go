package kata

func LongestConsec(strarr []string, k int) string {
    // your code
    n := len(strarr)
    if n == 0 || k > n || k <= 0 {
      return ""
    }
    
    i := 0
    ans := ""
    cur := 0
    maxInd := 0
    maxLen := 0
    for ; i < k; i ++ {
      cur += len(strarr[i])
      maxInd = i
    }
    maxLen = cur
    
    for ;i < n; i++ {
      cur += len(strarr[i]) - len(strarr[i - k])
      if cur > maxLen {
        maxLen = cur
        maxInd = i
      }
    }
    
    for i = maxInd; i > maxInd - k; i-- {
      ans = strarr[i] + ans
    }
    
    return ans
    
    
}
