import java.util.Map;

/**
 * Created by baislsl on 17-2-25.
 */
public class SuperWashingMachines {
    public class Solution {
        public int findMinMoves(int[] machines) {
            int avg = 0;
            for(int i=0;i<machines.length;i++){
                avg += machines[i];
            }
            if(avg%machines.length != 0) return -1;
            avg /= machines.length;
            int maxStep = 0, cur = 0;
            for(int i : machines){
                cur += i - avg;
                maxStep = Math.max(maxStep, Math.max(Math.abs(cur), i -avg));
            }
            return maxStep;

        }
    }

    public static void main(String[] args){
        int[] a = {0,3,0};
        System.out.println(new SuperWashingMachines().new Solution().findMinMoves(a));
    }
}
