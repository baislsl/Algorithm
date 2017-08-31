import java.util.ArrayList;
import java.util.Stack;

/**
 * Implement a basic calculator to evaluate a simple expression string.
 * <p>
 * The expression string may contain open ( and closing parentheses ),
 * the plus + or minus sign -, non-negative integers and empty spaces .
 * <p>
 * You may assume that the given expression is always valid.
 * <p>
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 */


public class _224BasicCalculator {
    private static ArrayList<String> calSplit(String s) {
        ArrayList<String> res = new ArrayList<>();
        int begin = 0;
        boolean flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (!flag && s.charAt(i) > ' ') {
                flag = true;
                continue;
            }
            if ((s.charAt(i) == '+' || s.charAt(i) == '-') && flag) {
                res.add(s.substring(begin, i).trim());
                res.add(s.substring(i, i + 1).trim());
                begin = i + 1;
            }
        }
        res.add(s.substring(begin).trim());
        return res;
    }

    private static int calWithNoBracket(String s) {
        ArrayList<String> spl = calSplit(s);

        int res = Integer.parseInt(spl.get(0));
        for (int i = 1; i < spl.size(); i += 2) {
            if (spl.get(i).equals("-"))
                res -= Integer.parseInt(spl.get(i + 1));
            else
                res += Integer.parseInt(spl.get(i + 1));
        }
        return res;
    }


    public static int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        while (true) {
            int lastBegin = -1;
            int leng = s.length() - 1;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') {
                    stack.push(i);
                } else if (s.charAt(i) == ')') {
                    lastBegin = stack.pop();
                    int a = calWithNoBracket(s.substring(lastBegin + 1, i));
                    if (a >= 0) {
                        s = s.substring(0, lastBegin) + Integer.toString(a) + s.substring(i + 1);
                        i = lastBegin;
                    } else {
                        int j = lastBegin - 1;
                        while (j >= 0) {
                            if (s.charAt(j) == '-') {
                                s = s.substring(0, j) + '+' + s.substring(j + 1);
                                a = -a;
                                break;
                            } else if (s.charAt(j) == '+') {
                                s = s.substring(0, j) + '-' + s.substring(j + 1);
                                a = -a;
                                break;
                            }
                            --j;
                        }
                        s = s.substring(0, lastBegin) + Integer.toString(a) + s.substring(i + 1);
                        i = lastBegin;
                    }
                }
            }
            break;
            // if (lastBegin == -1) break;
        }

        return calWithNoBracket(s);
    }


    public static void main(String[] args) {
        System.out.println(calculate("1 + 1"));
        System.out.println(calculate("-(-1+(4+5+2)-3)-(6+8)"));
        System.out.println(calculate("-(-1+(4+5+2)-(3-4))-(6+8)"));
        System.out.println(calculate("2-(5-6)"));

    }
}
