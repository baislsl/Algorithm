/**
 * Created by baislsl on 17-2-4.
 */
public class ZigZagConversion {
    public class Solution {
        public String convert(String s, int numRows) {
            StringBuffer[] str = new StringBuffer[numRows];
            for(int i=0;i<numRows;i++) str[i] = new StringBuffer();

            int i=0,length = s.length();
            if(numRows==1) return s;
            while(i<length){
                for(int j=0;j<numRows - 1&&i<length;j++){
                    str[j].append(s.charAt(i++));
                }
                for(int j=numRows - 1;j>=1&&i<length;j--){
                    str[j].append(s.charAt(i++));
                }
            }

            for(i=1;i<numRows;i++) str[0].append(str[i]);
            return str[0].toString();
        }
    }

    public int function(){
        return 1;
    }

    public static void main(String[] args){
        ZigZagConversion p = new ZigZagConversion();
        ZigZagConversion.Solution solution = p.new Solution();
        System.out.print(p.function());
    }
}
