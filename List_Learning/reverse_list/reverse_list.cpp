// 三个指针
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() { val = 0; next = nullptr; }
    ListNode(ListNode *s) { val = s->val; next = s->next; }
    ListNode(int a, ListNode* p) { val = a; next = p; }
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode* tmp1 = pHead;
        ListNode* tmp2 = tmp1;
        ListNode* tmp = pHead->next;
        while (tmp != nullptr)
        {
            tmp2 = tmp;
            tmp = tmp2->next;
            tmp2->next = tmp1;
            if (tmp1 == pHead) tmp1->next = nullptr;
            if (tmp == nullptr) return tmp2;
            else tmp1 = tmp2;
        }
        return tmp2;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    cin.get();
    int tmp;
    ListNode* p= new ListNode;
    ListNode* pp = p;
    ListNode* pt = p;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        p->val = tmp;
        if (i== n-1)
        {
            p->next = nullptr;
            break;
        }
        p->next = new ListNode;
        p = p->next;
    }
    ListNode* p2 = s.ReverseList(pp);
    ListNode* t1 = p2;
    for (int i = 0; i < n; i++)
    {
        cout << p2->val << ' ';
        p2 = p2->next;
    }
    return 0;
}
