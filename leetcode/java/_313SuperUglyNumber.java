/**
 * Write a program to find the nth super ugly number.
 * <p>
 * Super ugly numbers are positive numbers whose all prime factors are in the given
 * prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]
 * is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 * <p>
 * Note:
 * (1) 1 is a super ugly number for any given primes.
 * (2) The given numbers in primes are in ascending order.
 * (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 * <p>
 * Credits:
 * Special thanks to @dietpepsi for adding this problem and creating all test cases.
 */

import java.util.PriorityQueue;

/**
 * ...
 */

public class _313SuperUglyNumber {
    // 超时
    public static int nthSuperUglyNumber1(int n, int[] primes) {
        int[] a = new int[n + 2];
        int m = primes.length;
        a[0] = 1;

        for (int i = 1; i < n; i++) {
            a[i] = Integer.MAX_VALUE;

            for (int j = 0; j < m; j++) {
                int cur = i - 1;
                while (cur >= 0) {
                    int mul = a[cur] * primes[j];
                    if (mul <= a[i - 1]) break;
                    a[i] = Math.min(a[i], mul);
                    --cur;
                }

            }
        }


        return a[n - 1];
    }

    class One implements Comparable<One> {
        public long value;
        public int primeIndex;

        One(long value, int primeIndex) {
            this.value = value;
            this.primeIndex = primeIndex;
        }

        @Override
        public int compareTo(One var) {
            if(this.value > var.value) return 1;
            else if(this.value < var.value) return -1;
            else return 0;
            // error
            // return (int)(this.value - var.value);
        }
    }

    public int nthSuperUglyNumber(int n, int[] primes) {
        long[] a = new long[n + 1];
        a[0] = 1;
        PriorityQueue<One> pq = new PriorityQueue<>();

        pq.add(new One(a[0] * primes[0], 0));

        for (int i = 1; i < n; i++) {
            One top;
            do {
                top = pq.poll();
                long value = top.value;
                int index = top.primeIndex;
                if (index != primes.length - 1) {
                    pq.add(new One(value / primes[index] * primes[index + 1], index + 1));
                }
            } while (top.value == a[i - 1]);

            a[i] = top.value;
            pq.add(new One(a[i] * primes[0], 0));
            // System.out.println(i + " : " + a[i]);
        }


        return (int)a[n - 1];
    }

    public static void main(String[] args) {
        int[] primes = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
        System.out.println(new _313SuperUglyNumber().nthSuperUglyNumber(100000, primes));
    }

}
