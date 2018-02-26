// https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = A;

    ListNode *nextSlot = dummyHead;
    A = dummyHead;

    while (A != nullptr && A->next != nullptr) {
        if (A->next->val < B) {
            ListNode *curNode = A->next;
            A->next = A->next->next;

            curNode->next = nextSlot->next;
            nextSlot->next = curNode;

            if (nextSlot == A) {
                A = A->next;
            }
            nextSlot = nextSlot->next;
        } else {
            A = A->next;
        }
    }

    return dummyHead->next;
}
