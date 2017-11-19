import org.junit.Test;

import java.util.Arrays;
import static org.junit.Assert.*;

public class _213HouseRobberII {
    class Solution {
        public int rob(int[] nums) {
            if (nums.length <= 3) {
                int result = 0;
                for(int i : nums){
                    result = Math.max(result, i);
                }
                return result;
            }

            return Math.max(nums[0] + find1(nums), find2(nums));
        }


        private int find1(int[] nums) {
            int[] nn = new int[nums.length - 3];
            for (int i = 0; i < nn.length; i++) {
                nn[i] = nums[i + 2];
            }
            return find(nn);
        }

        private int find2(int[] nums) {
            int[] nn = new int[nums.length - 1];
            for(int i = 0; i < nn.length - 1; i++){
                nn[i] = nums[i + 1];
            }
            nn[nn.length - 1] = nums[nums.length - 1];
            return find(nn);
        }


        private int find(int[] nums){
            int[] ans = new int[nums.length + 1];

            ans[0] = 0;
            for (int i = 1; i <= nums.length; i++) {
                if (i != 1)
                    ans[i] = Math.max(ans[i - 1], nums[i - 1] + ans[i - 2]);
                else ans[i] = Math.max(ans[i - 1], nums[i - 1]);
            }

            return ans[nums.length];
        }
    }

    @Test
    public void test1(){
        int[] nums = {1, 2, 1, 1};
        assertEquals( 3, new Solution().find(nums));
    }
}
