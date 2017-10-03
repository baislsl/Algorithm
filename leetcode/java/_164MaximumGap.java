package others;

import org.junit.Test;

import java.util.Arrays;

/**
 * Given an unsorted array, find the maximum difference between the successive
 * elements in its sorted form.
 * <p>
 * Try to solve it in linear time/space.
 * <p>
 * Return 0 if the array contains less than 2 elements.
 * <p>
 * You may assume all elements in the array are non-negative integers and fit
 * in the 32-bit signed integer range.
 * <p>
 * Credits:
 * Special thanks to @porker2008 for adding this problem and creating all test cases.
 */
public class _164MaximumGap {
    class Solution {
        public int maximumGap(int[] nums) {
            if (nums.length <= 1) return 0;
            int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
            for (int i : nums) {
                min = Math.min(min, i);
                max = Math.max(max, i);
            }

            int[] b1 = new int[nums.length]; //min
            int[] b2 = new int[nums.length]; //max

            Arrays.fill(b1, Integer.MAX_VALUE);
            Arrays.fill(b2, Integer.MIN_VALUE);

            int maxGap = max - min;
            if (maxGap == 0) return 0;
            for (int i : nums) {
                int index = (int)((i - min) * 1.0 / (maxGap + 1) * nums.length);
                b1[index] = Math.min(b1[index], i);
                b2[index] = Math.max(b2[index], i);
            }

            int ans = maxGap / (nums.length - 1);
            int pre = Integer.MIN_VALUE, cur;
            for (int i = 0; i < nums.length; i++) {
                cur = b1[i];

                if (cur != Integer.MAX_VALUE && pre != Integer.MIN_VALUE)
                    ans = Math.max(ans, cur - pre);

                if (b2[i] != Integer.MIN_VALUE)
                    pre = b2[i];

            }

            return ans;
        }
    }

    @Test
    public void test() {
        int[] nums = {3, 7, -3, 20, 13};
        System.out.println(new Solution().maximumGap(nums));
    }

    @Test
    public void test2() {
        int[] nums = {15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463, 20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740};
        System.out.println(new Solution().maximumGap(nums));
    }

}
