

public class BuildapileofCubes {
    public static long findNb(long m) {
        if(m < 0) return -1;
        if(m == 0) return 0;

        long n = (long) Math.sqrt(m);

        if (n * n != m) return -1;

        long a = (long) Math.sqrt(2 * n);

        if (a * (a - 1) == 2 * n) return a - 1;
        else if (a * (a + 1) == 2 * n) return a;
        else if ((a + 1) * (a + 2) == 2 * n) return a - 1;
        return -1;
    }
}
