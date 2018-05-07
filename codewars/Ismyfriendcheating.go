package kata

func RemovNb(m uint64) [][2]uint64 {
    // your code
    ans := make([][2]uint64,0)
    var a, b uint64
    for a= 1; a <= m; a ++ {
      b = (m * (m +1) / 2 - a) / (a + 1)
      
      if a != b && a * b == m * (m + 1) / 2 - a - b && b <= m && b >= 1  {
        ans = append(ans, [2]uint64{a, b})
      }
    }
    if len(ans) == 0 {
      return nil
    } else {
      return ans 
    }

    
    
}