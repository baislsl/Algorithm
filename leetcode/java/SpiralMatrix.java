import java.util.ArrayList;
import java.util.List;

/**
 * Created by baislsl on 17-2-24.
 */
public class SpiralMatrix {
    public class Solution {
        int col, row;
        public List<Integer> spiralOrder(int[][] matrix) {

            row = matrix.length;
            if(row == 0) return new ArrayList<>();
            col = matrix[0].length;
            boolean[][] a = new boolean[row][col];
            int[][] direct = {{0,1},{1,0},{0,-1},{-1,0}};
            int count = col*row;
            ArrayList<Integer> ans = new ArrayList<>(count);
            int x, y, d;
            x = 0; y = -1;
            d = 0;

            while(count != 0){
                if(isLegal(x+=direct[d][0], y+=direct[d][1]) && !a[x][y]){
                    ans.add(matrix[x][y]);
                    a[x][y] = true;
                    count-=1;
                }else{
                    x-=direct[d][0]; y-=direct[d][1];
                    d = (d + 1)%4;
                }
            }


            return  ans;
        }

        boolean isLegal(int x, int y){
            return x>=0 && x<row && y>=0 && y<col;
        }

    }

    public static void main(String[] args){
        int[][] matrix = {{1,2,3}, {4,5,6}};
        System.out.println(matrix[0][1]);
        for(int a : new SpiralMatrix().new Solution().spiralOrder(matrix)){
            System.out.print(a + " ");
        }
    }

}
