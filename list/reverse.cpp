// https://www.interviewbit.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseList(ListNode* A) {
    if (A == nullptr || A->next == nullptr) {
        return A;
    }

    ListNode *prev = nullptr;
    ListNode *cur = A;
    ListNode *next = A->next;

    while (next != nullptr) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
    }
    cur->next = prev;

    return cur;
}
