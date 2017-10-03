package others;

import org.junit.Test;

/**
 * Given an input string, reverse the string word by word.
 * <p>
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * <p>
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 */

public class _151ReverseWordsinaString {


    public class Solution {

        public String reverseWords(String s) {
            return reverseWords(s, 0);
        }

        public String reverseWords(String s, int index) {
            for (int i = index; i < s.length(); i++) {
                if (s.charAt(i) == ' ') {
                    return (reverseWords(s, i + 1).trim() + ' ' + s.substring(index, i).trim()).trim();
                }
            }
            return s.substring(index);
        }
    }


    @Test
    public void test() {
        String s = "the sky is blue";
        s = "  ";
        System.out.println(new Solution().reverseWords(s).length());
    }
}
