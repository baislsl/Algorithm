import org.junit.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * <p>
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * Example:
 * Given nums = [1, 3, 5]
 * <p>
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed evenly.
 */

public class _307RangeSumQueryMutable {
    private static final Logger LOGGER = LoggerFactory.getLogger(NumArray.class);

    class NumArray {
        public int[][] matrix;
        public int height;

        public NumArray(int[] nums) {
            if(nums.length == 0){
                height = 0;
                matrix = null;
                return;
            }
            this.matrix = new int[(int) (Math.log(nums.length) / Math.log(2)) + 3][];
            this.matrix[0] = new int[nums.length];
            System.arraycopy(nums, 0, this.matrix[0], 0, nums.length);
            int length = nums.length;
            int h = 1;
            while (true) {
                matrix[h] = new int[length / 2 + 1];
                for (int i = 0; i * 2 < length; i++) {
                    matrix[h][i] = matrix[h - 1][i * 2];
                    if (i * 2 + 1 != length) {
                        matrix[h][i] += matrix[h - 1][i * 2 + 1];
                    }
                }
                if (length == 1) break;
                ++h;
                length = (length + 1) / 2;
            }
            height = h;
        }

        public void update(int i, int val) {
            if(matrix == null) return;
            int inc = val - matrix[0][i];
            int h = 0;
            int l = i;
            while (h != height) {
                matrix[h][l] += inc;
                ++h;
                l /= 2;
            }
        }

        public int sumRange(int i, int j) {
            if(matrix == null) return 0;
            if (j < i) return 0;
            if (i != 0) {
                return sumRange(0, j) - sumRange(0, i - 1);
            }
            /**
             * i : [0, log(n) ), j :
             * matrix[i][j]:
             *     [j * 2^i, (j + 1) * 2^i )
             *
             * 100100
             * (100, 1000)
             *
             *
             */
            int ans = matrix[0][j];

            // int ans = 0;
            // i = 0;
            // [0, j )
            i = 0;
            while (j != 0) {
                if (j % 2 == 1) {
                    ans += matrix[i][j - 1];
                }
                j /= 2;
                ++i;
            }
            return ans;
        }
    }


    @Test
    public void test1() {
        int[] nums = {2, 3, 4, 5, 6};
        NumArray s = new NumArray(nums);
        int[][] m = s.matrix;
        int l = m.length;
        for (int i = 0; i < l; i++) {
            for(int j = 0;j<m[i].length;j++){
                LOGGER.info("{}:{} -> {}", i, j, m[i][j]);
            }
        }
        s.update(2, 0);
        LOGGER.info("{}", s.sumRange(2 , 3));
        LOGGER.info("{}", s.sumRange(2 , 4));
        LOGGER.info("{}", s.sumRange(1 , 3));

    }

    @Test
    public void test2(){
        int[] nums = {};
        NumArray s = new NumArray(nums);
    }


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
}
