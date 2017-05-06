/**
 * given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 k is a positive integer and is less than or equal to the length of the linked list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.

 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5

 For k = 3, you should return: 3->2->1->4->5
 * */


import java.util.List;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class ReverseNodesinkGroup{
    public class Solution {
        public class ListNode{
            int val;
            ListNode next;
            ListNode(int x){
                val = x;
            }
        }


        public ListNode reverseKGroup(ListNode head, int k) {
            ListNode dummy  = head;
            if(dummy == null) return null;
            int temp = k;
            while(--temp!=0 && dummy.next != null){
                dummy = dummy.next;
            }
            if(dummy.next == null && temp != 0) return head;
            ListNode tail = new ListNode(0);
            tail.next = head;
            while(tail.next != null){
                ListNode nextTail = tail.next;
                ListNode p =  reverse(tail, k);
                if(p == null) break;
                tail = nextTail;
            }

            return dummy;
        }

        public ListNode reverse(ListNode head, int k){
            ListNode nextTail = head.next;

            ListNode test = head;
            int tmp = k;
            while(--tmp != 0){
                test=test.next;
                if(test.next == null)
                    return null;
            }
            ListNode tmpHead = head;
            head = head.next;
            ListNode p = head.next;
            while(--k!=0 && p!=null){
                ListNode p1 = p.next;
                p.next = head;

                head = p;
                p = p1;

            }
            tmpHead.next = head;
            nextTail.next = p;
            return p;
        }

    }

    public static void main(String[] args){
        Solution.ListNode list1 = new ReverseNodesinkGroup().new Solution().new ListNode(1);
        Solution.ListNode list2 = new ReverseNodesinkGroup().new Solution().new ListNode(2);
        Solution.ListNode list3 = new ReverseNodesinkGroup().new Solution().new ListNode(3);
        Solution.ListNode list4 = new ReverseNodesinkGroup().new Solution().new ListNode(4);
        list1.next = list2;list2.next = list3;list3.next = list4;list4.next = null;
        Solution.ListNode p = new ReverseNodesinkGroup().new Solution().reverseKGroup(list1, 1);
        while(p != null){
            System.out.println(p.val);
            p = p.next;
        }
    }
}

