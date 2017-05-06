import java.util.ArrayList;
import java.util.List;

/**
 * Created by baislsl on 17-2-24.
 */
public class N_Queens {
    public class Solution {

        public List<List<String>> solveNQueens(int n) {
            int[] a = new int[n];
            boolean[] col = new boolean[n];
            boolean[] d1 = new boolean[2*n];
            boolean[] d2 = new boolean[2*n];

            for(int i=0;i<n;i++){
                a[i] = -1;
            }

            List<List<String>> ans = new ArrayList<>();

            dfs(a, col, d1,d2, 0, n, ans);
            return ans;
        }

        public void dfs(int[] a, boolean[] col, boolean[] d1, boolean[]d2, int cur, int n, List<List<String>> ans){
            if(cur == n){
                ans.add(convert(a, n));
                return;
            }
            for(int i=0;i<n;i++){
                if(!col[i] && !d1[i+cur] && !d2[i-cur+n] ){
                    col[i] = true;
                    d1[i+cur] = true;
                    d2[i-cur+n] = true;
                    a[cur] = i;
                    dfs(a, col, d1,d2, cur+1, n, ans);
                    col[i] = false;
                    d1[i+cur] = false;
                    d2[i-cur+n] = false;
                    a[cur] = -1;
                }
            }
        }

        ArrayList<String> convert(int[] a, int n){
            ArrayList<String> result = new ArrayList<>(n);

            for(int x=0;x<n;x++){
                StringBuilder str = new StringBuilder();
                for(int y=0;y<n;y++){
                    str.append(y == a[x] ? "Q" : ".");
                }
                result.add(str.toString());
            }
            return result;

        }

    }


    public static void main(String[] args){
        List<List<String>> lists = new N_Queens().new Solution().solveNQueens(4);
        for(List<String> list : lists){
            for (String string : list){
                System.out.println(string);
            }
            System.out.println();
        }
    }

}
