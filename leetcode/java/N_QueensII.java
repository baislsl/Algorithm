import java.util.ArrayList;
import java.util.List;

/**
 * Created by baislsl on 17-2-24.
 */
public class N_QueensII {
    public class Solution {
        int ans = 0;
        public int totalNQueens(int n) {
            int[] a = new int[n];
            boolean[] col = new boolean[n];
            boolean[] d1 = new boolean[2*n];
            boolean[] d2 = new boolean[2*n];

            for(int i=0;i<n;i++){
                a[i] = -1;
            }


            dfs(a, col, d1,d2, 0, n);
            return ans;
        }

        public void dfs(int[] a, boolean[] col, boolean[] d1, boolean[]d2, int cur, int n){
            if(cur == n){
                ans+=1;
                return;
            }
            for(int i=0;i<n;i++){
                if(!col[i] && !d1[i+cur] && !d2[i-cur+n] ){
                    col[i] = true;
                    d1[i+cur] = true;
                    d2[i-cur+n] = true;
                    a[cur] = i;
                    dfs(a, col, d1,d2, cur+1, n);
                    col[i] = false;
                    d1[i+cur] = false;
                    d2[i-cur+n] = false;
                    a[cur] = -1;
                }
            }
        }

    }

    public static void main(String[] args){
        System.out.println(new N_QueensII().new Solution().totalNQueens(4));
    }

}
