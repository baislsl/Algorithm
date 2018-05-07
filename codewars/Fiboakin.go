package kata 

var table = map[int]int{
  1 : 1,
  2 : 1,
}

func un(n int) int {
  if table[n] == 0 {
    table[n] = un(n-un(n-1)) + un(n-un(n-2))
  }
  return table[n]
}


func LengthSupUk(n, k int) int {
  var cnt int = 0
  for i := 1; i <=n ;i++ {
    if un(i) >= k{
      cnt++
    }
  }
  return cnt
}
func Comp(n int) int {
  var cnt int = 0
  for i := 1; i <= n - 1; i++ {
    if un(i) > un(i + 1) {
      cnt++
    }
  }
  return cnt
}
