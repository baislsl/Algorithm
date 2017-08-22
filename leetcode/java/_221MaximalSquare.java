/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 * <p>
 * For example, given the following matrix:
 * <p>
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 4.
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
 */

public class _221MaximalSquare {

    private static int coverLine(char[] matrix, int result[], int i) {
        if (i >= matrix.length) return 0;
        int re = coverLine(matrix, result, i + 1);
        if (matrix[i] == '0') result[i] = 0;
        else result[i] = re + 1;
        return result[i];
    }

    private static int coverRow(int[][] matrix, int[][] result, int first, int i) {
        if (i == matrix.length - 1) return result[i][first] = 1;
        int re = coverRow(matrix, result, first, i + 1);
        if (matrix[i][first] <= matrix[i + 1][first]) {
            return result[i][first] = re + 1;
        } else {
            return result[i][first] = 1;
        }

    }

    private static int coverRow2(int[][] matrix, int[][] result, int first, int i) {
        if (i == 0) return result[i][first] = 1;
        int re = coverRow2(matrix, result, first, i - 1);
        if (matrix[i][first] <= matrix[i - 1][first]) {
            return result[i][first] = re + 1;
        } else {
            return result[i][first] = 1;
        }
    }

    private static void fline(char[] matrix, int[] result) {
        coverLine(matrix, result, 0);
    }

    private static void frow(int[][] matrix, int[][] result1, int[][] result2, int first) {
        coverRow(matrix, result1, first, 0);
        coverRow2(matrix, result2, first, matrix.length - 1);
    }


    // bugs
    public  static int maximalSquare2(char[][] matrix) {
        int a = matrix.length, b;
        if (a == 0) return 0;
        b = matrix[0].length;


        int[][] f = new int[a][b], s1 = new int[a][b], s2 = new int[a][b];

        for (int i = 0; i < a; i++) {
            fline(matrix[i], f[i]);
        }

        for (int i = 0; i < b; i++) {
            frow(f, s1, s2, i);
        }

        int result = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                result = Math.max(result, Math.min(f[i][j] , s1[i][j] + s2[i][j] - 1));
                // result = Math.max(result, Math.min(f[i][j] , ));
                // result = Math.max(result, f[i][j] * s2[i][j]);
            }
        }
        return result*result;
    }

    public static int maximalSquare(char[][] matrix){
        int a = matrix.length, b;
        if (a == 0) return 0;
        b = matrix[0].length;
        int[][] result = new int[a][b];
        int maxSize = 0;

        for(int i=0;i<a;i++){
            if(matrix[i][0] == '1'){
                result[i][0] =1;
                maxSize = 1;
            }
        }
        for(int i=0;i<b;i++){
            if(matrix[0][i] == '1'){
                result[0][i] = 1;
                maxSize = 1;
            }
        }

        for(int i=1;i<a;i++){
            for(int j=1;j<b;j++){
                if(matrix[i][j] == '1'){
                    result[i][j] = Math.min(result[i - 1][j], Math.min(result[i - 1][j - 1], result[i][j - 1])) + 1;
                    maxSize = Math.max(maxSize, result[i][j]);
                }
            }
        }
        return maxSize*maxSize;



    }


    public static void main(String[] args) {
        char[][] matrix = {
                {1, 0, 1, 0, 0},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 0, 0, 1, 0}
        };

        char[][] m2 = new char[5][4];
        for(int i=0;i<matrix.length;i++)
            for(int j=0;j<matrix[0].length;j++){
                matrix[i][j] += '0';
                m2[j][i] = matrix[i][j];
            }


        System.out.println(maximalSquare(m2));
        System.out.println(maximalSquare(matrix));
    }
}
