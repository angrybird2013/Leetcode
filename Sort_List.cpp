/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head) {
        return head == NULL?0:1+length(head->next);
    }
    
    ListNode *split(ListNode *head, int length) {
        ListNode *tmp = head, *next;
        length /= 2;
        while(--length>0) {
            tmp = tmp->next;
        }
        next = tmp->next;
        tmp->next = NULL;
        return next;
    }
    
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode *tmp, *head;
        if(a->val > b->val) {
            tmp = b;
            b = a;
            a = tmp;
        }
        head = a;
        a = a->next;
        tmp = head;
        while(a != NULL && b != NULL) {
            if(a->val < b->val) {
                tmp->next = a;
                a = a->next;
            }
            else {
                tmp->next = b;
                b = b->next;
            }
            tmp = tmp->next;
        }
        if(a == NULL)
            tmp->next = b;
        else
            tmp->next = a;
        return head;
    }

    ListNode *sortList(ListNode *head) {
        int l = length(head);
        if(l < 2)
            return head;
        ListNode *next = split(head, l);
        head = sortList(head);
        next = sortList(next);
        return merge(head, next);
    }
};