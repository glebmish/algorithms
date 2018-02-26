// https://www.interviewbit.com/problems/intersection-of-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* list) {
    int len = 0;
    while (list != nullptr) {
        list = list->next;
        len++;
    }

    return len;
}

ListNode* steps(ListNode* list, int steps) {
    while (list != nullptr && steps != 0) {
        list = list->next;
        steps--;
    }

    return list;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int lenA = len(A);
    int lenB = len(B);

    if (lenA > lenB) {
        A = steps(A, lenA - lenB);
    } else {
        B = steps(B, lenB - lenA);
    }

    while (A != B) {
        A = A->next;
        B = B->next;
    }

    return A;
}

