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
        ListNode* rs = new ListNode(0);
        auto tmp = rs;
        if (p1 == nullptr) return p2;
        if (p2 == nullptr) return p1;
        while (p1 != nullptr || p2 != nullptr)
        {
            if (p1 == nullptr)
            {
                tmp->val = p2->val;
                tmp->next = p2->next;
                break;
            }
            if (p2 == nullptr)
            {
                tmp->val = p1->val;
                tmp->next = p1->next;
                break;
            }
            if (p1->val <= p2->val)
            {
                tmp->val = p1->val;
                tmp->next = new ListNode(0);
                tmp = tmp->next;
                p1 = p1->next;
            }
            else  //这里原来写的是if(p2->val<p1->val) 这样在上一个判断结束后不会更新循环，而是再进行这个判断，如果p1==nullptr 则报错
            {
                tmp->val = p2->val;
                tmp->next = new ListNode(0);
                tmp = tmp->next;
                p2 = p2->next;
            }
        }
        return rs;
    }
};