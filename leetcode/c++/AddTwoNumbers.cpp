#include <cstdlib>

/**
 * Definition for singly-linked list.
 *
 */
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode* getNew(){
    struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
    l->next = NULL;
    return l;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head,*p,*tail;
    p = head = NULL;
    int add = 0;
    while(l1!= NULL&&l2!=NULL){
        p=getNew();
        if(head == NULL){
            head = p;
        }else{
            tail->next = p;
        }
        tail = p;
        p->val = l1->val + l2->val + add;
        if(p->val > 9){
            add = 1;
            p->val -= 10;
        }else{
            add = 0;
        }
        l1 = l1->next;
        l2 = l2->next;


    }

    while(l1!= NULL){
        p=getNew();
        if(head == NULL){
            head = p;
        }else{
            tail->next = p;
        }
        tail = p;
        p->val = l1->val + add;
        if(p->val>9){
            add = 1;
            p->val -= 10;
        } else{
            add = 0;
        }
        l1 = l1->next;
    }

    while(l2!= NULL){
        p=getNew();
        if(head == NULL){
            head = p;
        }else{
            tail->next = p;
        }
        tail = p;
        p->val = l2->val + add;
        if(p->val>9){
            add = 1;
            p->val -= 10;
        }else{
            add = 0;
        }
        l2 = l2->next;
    }

    if(add == 1){
        p=getNew();
        p->val = add;
        tail->next = p;
    }

    return head;
}

