// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next) return head;
        ListNode *firstHead = NULL, *firstTail = NULL;
        ListNode *secondHead = NULL, *secondTail = NULL;
        ListNode *cur = head;
        while(cur) {
            if(cur->val < x) {
                if(!firstHead) firstHead = cur;
                if(firstTail) firstTail->next = cur;
                firstTail = cur;
            } else {
                if(!secondHead) secondHead = cur;
                if(secondTail) secondTail->next = cur;
                secondTail = cur;
            }
            cur = cur->next;
        }
        if(firstTail) firstTail->next = secondHead;
        if(secondTail) secondTail->next = NULL;
        return firstHead ? firstHead : secondHead;
    }
};
