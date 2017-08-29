import java.util.ArrayList;
import java.util.List;

/**
 * Created by baislsl on 17-2-27.
 */
public class TextJustification {
    public class Solution {
        public List<String> fullJustify(String[] words, int maxWidth) {
            ArrayList<String> ans = new ArrayList<>();
            int length = words.length;

            int from = 0;
            int to = 0;
            // from <= x < to;
            while(from < length){
                int sum = -1;
                while(to < length){
                    if(sum + 1 + words[to].length() <= maxWidth){
                        sum += 1 + words[to].length();
                        to += 1;
                    }else{
                        break;
                    }
                }

                ans.add(generate(from, to, maxWidth, sum, words, to == length));
                from = to;
            }
            return ans;
        }

        private String generate(int from, int to, int maxWidth, int sum, String[] words, boolean flag){
            if(flag){
                String s = new String(words[from]);
                for (int i=from + 1;i<to;i++){
                    s += " " + words[i];
                }
                while(s.length() < maxWidth) s += " ";
                return s;

            }
            int num = to - from - 1;
            sum -= num;
            int extra = maxWidth - sum;

            if(num == 0){
                String str = new String(words[from]);
                while(str.length() != maxWidth){
                    str += " ";
                }
                return str;
            }
            int minBlank = extra/num;
            int left = extra - num*minBlank;

            String s1 = "";
            for(int i=0;i<minBlank;i++) s1+=" ";
            String s2 = s1 + " ";

            String str = "";

            for(int i=from;i<to;i++){
                if(i!=from){
                    if(left > 0){
                        str += s2;
                        left -= 1;
                    }else{
                        str += s1;
                    }
                }
                str +=  words[i];
            }
//            System.out.println(str.length());
            return str;
        }
    }
}
