// https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if (A == nullptr || A->next == nullptr) {
        return nullptr;
    }

    ListNode *slow = A->next, *fast = A->next->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    while (A != slow) {
        A = A->next;
        slow = slow->next;
    }

    return A;
}
