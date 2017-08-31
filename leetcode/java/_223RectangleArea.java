


public class _223RectangleArea {

    private static long comm(int a, int b, int c, int d) {
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        if(c > d){
            int t = c;
            c=  d;
            d = t;
        }

        if(Math.min(b ,d) < Math.max(a, c)) return 0;
        long r = Math.min(b, d) - Math.max(a, c);
        return r < 0 ? 0 : r;
    }

    private static long sq(int a, int b , int c, int d){
        return Math.abs(a - c) * Math.abs(d - b);
    }


    public static int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return  (int)(sq(A, B, C, D)  -  comm(A, C, E, G) * comm(B, D, F, H) + sq(E, F, G, H));

    }


    public static void main(String[] args){
        System.out.println(computeArea(-1500000001,0
                ,-1500000000,1
                ,1500000000,0
                ,1500000001,1));
    }
}