public class _198HouseRobber {
    class Solution {


        public int rob(int[] nums) {
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

}
