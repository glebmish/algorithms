// https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseTo(ListNode* A, int B) {
    ListNode *head = A;

    ListNode *prev = nullptr, *cur = A, *next = cur->next;

    while (B != 0) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
        B--;
    }
    cur->next = prev;

    A->next = next;
    return cur;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = A;
    A = dummyHead;

    int revLen = C - B;

    B--;
    while (B != 0) {
        A = A->next;
        B--;
    }

    A->next = reverseTo(A->next, revLen);
    return dummyHead->next;
}
