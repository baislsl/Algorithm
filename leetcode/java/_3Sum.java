import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by baislsl on 17-2-23.
 */
public class _3Sum {
    // in this problem, no need to divide them into positive and negative, although I do it
    public class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            List<List<Integer>> ans = new ArrayList<>();
            Arrays.sort(nums);

            int negativeLeft = 0, negativeRight = -1;
            int positiveLeft = nums.length, positiveRight = nums.length - 1;

            if(nums.length == 0) return ans;
            //fing negativeRight and positiveLeft
            int i=0;
            while(nums[i] < 0){
                negativeRight = i;
                if(++i == nums.length) break;
            }
            i=nums.length - 1;
            while(nums[i] > 0){
                positiveLeft = i;
                if(--i == -1) break;
            }

            List<List<Integer>> temp =
                    find(nums, negativeLeft, negativeRight, positiveLeft, positiveRight);
            for(List<Integer> list : temp) ans.add(list);

            temp = find(nums, positiveLeft, positiveRight, negativeLeft, negativeRight);
            for(List<Integer> list : temp) ans.add(list);

            if(negativeRight != positiveLeft - 1){  // 0 exist
                int negative = negativeLeft, positive = positiveRight;
                while(negative <= negativeRight && positive >= positiveLeft){
                    if(nums[negative] + nums[positive] == 0){
                        ans.add(New(nums[negative], 0, nums[positive]));
                        do{
                            positive--;
                        }while(positive >= positiveLeft && nums[positive] == nums[positive + 1]);

                        do{
                            negative++;
                        } while(negative <= negativeRight && nums[negative] == nums[negative - 1]);
                    }else if(nums[negative] + nums[positive] > 0){
                        do{
                            positive--;
                        }while(positive >= positiveLeft && nums[positive] == nums[positive + 1]);
                    }else{
                        do{
                            negative++;
                        } while(negative <= negativeRight && nums[negative] == nums[negative - 1]);                }
                }
            }

            if(negativeRight + 4 <= positiveLeft) {
                ans.add(New(0,0,0));
            }

            return ans;
        }

        public ArrayList<Integer> New(int a, int b, int c){
            ArrayList<Integer> list = new ArrayList<>(3);
            list.add(a);list.add(b);list.add(c);
            return list;
        }

        public List<List<Integer>> find(int[] nums, int leftBegin, int leftEnd,
                         int rightBegin, int rightEnd){
            List<List<Integer>> ans = new ArrayList<>();

            for(int i=leftBegin;i<=leftEnd;i++){
                if(i!=leftBegin && nums[i] == nums[i - 1]) continue;
                int right = rightEnd;
                int left = rightBegin;
                int cur = nums[i];
                while(left < right){
                    int sum = nums[left] + nums[right] + cur;
                    if(sum == 0){
                        if(cur < 0)
                            ans.add(New(cur,nums[left],nums[right]));
                        else
                            ans.add(New(nums[left], nums[right], cur));

                        right--;left++;
                    }else if(sum > 0){
                        right--;
                    }else if(sum < 0){
                        left++;
                    }

                }

            }
            // delete the same note
            int a = 0, b = 0, c =1;
            List<List<Integer>> newList = new ArrayList<>();
            for(List<Integer> list : ans){
                if(list.get(0) == a && list.get(1) == b && list.get(2) == c){}
                else{
                    newList.add(list);
                    a = list.get(0);
                    b = list.get(1);
                    c = list.get(2);
                }
            }

            return newList;
        }

    }

    public static void main(String[] args){
        int[] nums ={-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
        System.out.println(new _3Sum().new Solution().threeSum(nums));
    }
}
