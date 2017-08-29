import java.util.ArrayList;


/**
 * Created by baislsl on 17-2-22.
 */
public class ContainerWithMostWater {


    public class Solution {
        public int maxArea(int[] height) {
            ArrayList<Integer> left = new ArrayList<>();
            ArrayList<Integer> right = new ArrayList<>();
            int length =height.length;

            int[] leftIndex = new int[length];
            int[] rightIndex = new int[length];

            int max = height[0];
            left.add(height[0]);
            leftIndex[0] = 0;
            for(int i=1;i<length;i++){
                if(height[i] > max){
                    leftIndex[left.size()] = i;
                    left.add(height[i]);
                    max = height[i];
                }
            }

            max = height[length - 1];
            right.add(max);
            rightIndex[0] = length - 1;
            for(int i=length-2;i>=0;i--){
                if(height[i] > max){
                    rightIndex[right.size()] = i;
                    right.add(height[i]);
                    max = height[i];
                }
            }

            int ans = 0;
            for(int i=0;i<left.size();i++){
                for(int j =0;j<= right.size()-1;j++){
                    int square = (rightIndex[j] - leftIndex[i]) * Math.min(left.get(i), right.get(j));
                    if(square > ans)
                        ans = square;
                    if(right.get(j) >= left.get(i))
                        break;
                }

            }
            return ans;
        }
    }


    //　暴力计算 超时
    public class Solution2 {
        public int maxArea(int[] height) {
            int max = 0;
            for(int i=0;i<height.length - 1; i++){
                for(int j=i + 1;j<height.length;j++){
                    int square = (j - i) * java.lang.Integer.min(height[i], height[j]);
                    if(square > max)
                        max = square;
                }
            }
            return max;
        }
    }

    //O(n) copy form others'solution
    public class Solution3{
        public int maxArea(int[] height) {
            int left = 0, right = height.length - 1;
            int maxArea = 0;

            while (left < right) {
                maxArea = Math.max(maxArea, Math.min(height[left], height[right])
                        * (right - left));
                if (height[left] < height[right])
                    left++;
                else
                    right--;
            }

            return maxArea;
        }
    }

    public static void main(String[] args){
        int[] a = {1,2,1};
        System.out.println(new ContainerWithMostWater().new Solution().maxArea(a));
    }

}
