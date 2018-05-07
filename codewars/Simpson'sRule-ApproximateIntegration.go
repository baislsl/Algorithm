package kata

import "math"

func f(x float64) float64 {
  return math.Pow(math.Sin(x), 3)
}

func Simpson(n int) float64 {
    // your code
    fn := float64(n)
    var ans float64 = f(0) + f(math.Pi)
    var h float64 = math.Pi / fn
    for i := 1; i <= n / 2; i ++ {
      ans += 4 * f(float64(2 * i - 1) *h)
    }
    for i := 1; i <= n / 2 - 1; i ++ {
      ans += 2 * f(2 * float64(i) * h )
    }
    
    return ans * math.Pi / ( 3 * fn ) * 1.5;
    
    
}
