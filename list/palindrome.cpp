// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode *A) {
    int len = 0;
    while (A != nullptr) {
        A = A->next;
        len++;
    }

    return len;
}

ListNode* steps(ListNode *A, int steps) {
    while (A != nullptr && steps != 0) {
        A = A->next;
        steps--;
    }

    return A;
}

ListNode* reverse(ListNode *A) {
    if (A == nullptr || A->next == nullptr) {
        return A;
    }

    ListNode *prev = nullptr, *cur = A, *next = A->next;
    while (next != nullptr) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
    }
    cur->next = prev;

    return cur;
}

int Solution::lPalin(ListNode* A) {
    int len = length(A);
    ListNode *premid = steps(A, (len - 1) / 2);

    ListNode *mid;
    if (len % 2 == 1) {
        mid = premid;
    } else {
        mid = premid->next;
        premid->next = nullptr;
    }

    ListNode *rev = reverse(mid);

    while (A != nullptr && rev != nullptr) {
        if (A->val != rev->val) {
            return 0;
        }
        A = A->next;
        rev = rev->next;
    }

    return 1;
}
