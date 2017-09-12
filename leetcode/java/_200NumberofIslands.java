import org.junit.Test;

/**
 * Given a 2d grid map of '1's (land) and '0's (water),
 * count the number of islands. An island is surrounded by water
 * and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.
 * Example 1:
 * <p>
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 * <p>
 * Example 2:
 * <p>
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 */

public class _200NumberofIslands {

    class Solution {
        int[][] dir = {
                {0, 1}, {0, -1}, {-1, 0}, {1, 0}
        };
        private void dfs(int x, int y,int[][] flag, char[][] grid, int cnt, int m, int n){
            flag[x][y] = cnt;
            for(int i = 0;i < dir.length;i++){
                int x0 = x + dir[i][0];
                int y0 = y + dir[i][1];
                if(x0 >= 0 && x0 < m && y0 >= 0 && y0 < n && flag[x0][y0] == 0 && grid[x0][y0] == '1'){
                    dfs(x0, y0, flag, grid, cnt, m , n);
                }

            }

        }


        public int numIslands(char[][] grid) {

            int cnt = 0;
            int m = grid.length;
            if (m == 0) return 0;

            int n = grid[0].length;
            if (n == 0) return 0;
            int[][] flag = new int[m][n];


            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    flag[i][j] = 0;
                }
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if(flag[i][j] == 0 && grid[i][j] == '1'){
                        dfs(i, j, flag, grid, ++cnt, m, n);
                    }

                }
            }

            return cnt;

        }
    }

    @Test
    public void test(){

    }
}
