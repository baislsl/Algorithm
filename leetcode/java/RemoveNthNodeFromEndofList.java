/**
 * Created by baislsl on 17-2-17.
 */


import java.util.ListResourceBundle;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */



public class RemoveNthNodeFromEndofList {
    int count;
    public ListNode removeNthFromEnd(ListNode head, int n) {

        count = n;
        return myAnswer(head);

    }

    private ListNode myAnswer(ListNode head){
        if(head == null) return null;
        else{
            head.next = myAnswer(head.next);
            if(count==1){
                count = 0;
                return head.next;
            }else{

                count -= 1;
                return head;
            }
        }



    }

    private static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }
}

