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
        auto rs = new ListNode(0);
        auto tmp = rs;//ÐéÄâÖ¸ÕëÍ·
        merge(p1, p2, tmp);
        return rs->next;
    }
    void merge(ListNode* p1, ListNode* p2, ListNode* rs)
    {
        if (p1 == nullptr)
        {
            rs->next = p2;
            return;
        }
        if (p2 == nullptr)
        {
            rs->next = p1;
            return;
        }
        if (p1->val <= p2->val)
        {
            rs->next = new ListNode(p1->val);
            rs = rs->next;
            p1 = p1->next;
        }
        else
        {
            rs->next = new ListNode(p2->val);
            rs = rs->next;
            p2 = p2->next;
        }
        merge(p1, p2, rs);
    }
};