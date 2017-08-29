import java.util.Arrays;

/**
 * Created by baislsl on 17-2-23.
 */
public class _3SumClosest {
    public class Solution {
        public int threeSumClosest(int[] nums, int target) {
            int ans = Integer.MAX_VALUE;
            int ret = 0;
            Arrays.sort(nums);
            for(int i=0;i<nums.length - 2;i++){
                int left = i + 1 ,right = nums.length - 1;
                int cur = nums[i];
                while(left < right){
                    int distance = nums[left] + nums[right] + cur - target;
                    if(Math.abs(distance) < ans ){
                        ans = Math.abs(distance) ;
                        ret = nums[left] + nums[right] + cur;
                    }
                    if(distance > 0){
                        right--;
                    }else if(distance < 0){
                        left++;
                    }else{
                        return target;
                    }
                }
            }
            return ret;

        }
    }

    public static void main(String[] args){
        int[] a = {0,2,1,-3};
        System.out.println(new _3SumClosest().new Solution().threeSumClosest(a, 1));
    }
}
