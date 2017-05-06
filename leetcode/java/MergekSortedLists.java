import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

/**
 *
 * case 1: just merge by one time, 6 * n
 * case 2: merge two by two
 *
 * */
public class MergekSortedLists {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public class Solution {

        public ListNode mergeTwoLists(ListNode list1, ListNode list2){
            ListNode list, head, end;
            end = head = null;
            while(list1 != null && list2 != null){
                if(list1.val < list2.val){
                    list = new ListNode(list1.val);
                    list1 = list1.next;
                    if(head == null)
                        head = list;
                    else
                        end.next = list;
                    end = list;
                }else {
                    list = new ListNode(list2.val);
                    list2 = list2.next;
                    if (head == null)
                        head = list;
                    else
                        end.next = list;
                    end = list;
                }
            }

            while (list1!=null){
                list = new ListNode(list1.val);
                list1 = list1.next;
                if (head == null)
                    head = list;
                else
                    end.next = list;
                end = list;
            }

            while(list2!=null){
                list = new ListNode(list2.val);
                list2 = list2.next;
                if (head == null)
                    head = list;
                else
                    end.next = list;
                end = list;
            }
            return head;
        }

        public ListNode mergeKLists(ListNode[] lists) {
            return merge(lists, 0, lists.length);
        }

        public ListNode merge(ListNode[] lists, int form, int length){
            if(length == 1) return lists[form];
            else if(length == 0) return null;
            else{
                return mergeTwoLists(merge(lists, form, length/2),
                        merge(lists, form + length/2, length - length/2));
            }
        }
    }

    public class  Solution2{
        // use priority queue
        public ListNode mergeKLists(ListNode[] lists){
            if(lists.length == 0) return null;
            PriorityQueue<ListNode> priorityQueue = new PriorityQueue<ListNode>(lists.length,
                    new Comparator<ListNode>() {
                        @Override
                        public int compare(ListNode o1, ListNode o2) {
                            if(o1.val > o2.val) return 1;
                            else if(o1.val == o2.val) return 0;
                            else return -1;
                        }
                    }
            );

            for(ListNode list : lists){
                if(list != null)
                    priorityQueue.add(list);
            }

            ListNode dummy = new ListNode(0), tail = dummy;
            while (!priorityQueue.isEmpty()){
                tail.next = priorityQueue.poll();
                tail = tail.next;
                if(tail.next != null){
                    priorityQueue.add(tail.next);
                }
            }
            return dummy.next;


        }

    }

    public static void main(String[] args){
        ListNode[] lists = new ListNode[2];

        ListNode p = new MergekSortedLists().new Solution2().mergeKLists(lists);
        //System.out.println(p.val);
    }
}
