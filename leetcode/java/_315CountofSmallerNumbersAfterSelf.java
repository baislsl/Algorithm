import java.util.ArrayList;
import java.util.List;

/**
 * You are given an integer array nums and you have to return a new counts array.
 * The counts array has the property where counts[i] is the number of smaller elements
 * to the right of nums[i].
 * <p>
 * Example:
 * Given nums = [5, 2, 6, 1]
 * <p>
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * Return the array [2, 1, 1, 0].
 */


public class _315CountofSmallerNumbersAfterSelf {
    class Node {
        int value;
        int index;
        int leftNum;
        int childNum;
        Node left, right;

        Node(int value, int index) {
            this.value = value;
            this.index = index;
            left = right = null;
            childNum = 0;
            leftNum = 0;
        }
    }

    public Node insert(Node cur, List<Integer> ans, int index, int sum, Node icur) {
        if (cur == null) {
            ans.set(index, sum);
            return icur;
        } else {
            if (cur.value < icur.value) {
                cur.right = insert(cur.right, ans, index, sum + cur.leftNum + 1, icur);
            } else {
                cur.left = insert(cur.left, ans, index, sum, icur);
                ++cur.leftNum;
            }
            return cur;
        }
    }

    public List<Integer> countSmaller(int[] nums) {
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) ans.add(0);
        if (nums.length == 0) return ans;

        Node root = null;
        for (int i = nums.length - 1; i >= 0; --i) {
            Node node = new Node(nums[i], i);
            root = insert(root, ans, i, 0, node);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {5, 2, 6, 2, 1, -4, 2, 100, 3};
        List<Integer> ans = new _315CountofSmallerNumbersAfterSelf().countSmaller(nums);
        System.out.println(ans);
    }


}
