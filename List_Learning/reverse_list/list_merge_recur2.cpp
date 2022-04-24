/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* Merge(ListNode* p1, ListNode* p2)
    {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val < p2->val)
        {
            p1->next = Merge(p1->next, p2);
            return p1;
        }
        else
        {
            p2->next = Merge(p1, p2->next);
            return p2;
        }
    }
};