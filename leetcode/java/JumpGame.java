/**
 * Created by baislsl on 17-2-25.
 */
public class JumpGame {
    public class Solution {
        public boolean canJump(int[] nums) {
            int length = nums.length;
            boolean flag = true;

            int first = 1;
            for(int i=length - 2;i>=0;i--){
                if(nums[i]>=first){
                    flag = true;
                    first = 1;
                }else{
                    flag = false;
                    first += 1;
                }
            }

            return flag;
        }
    }
}
