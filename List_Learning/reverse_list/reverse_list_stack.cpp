// ”√stack¥Ê¥¢
#include <iostream>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() { val = 0; next = nullptr; }
    ListNode(ListNode* s) { val = s->val; next = s->next; }
    ListNode(int a, ListNode* p) { val = a; next = p; }
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        stack<ListNode*> rs;
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        while (pHead != nullptr)
        {
            rs.push(pHead);
            pHead = pHead->next;
        }
        pHead = rs.top();
        ListNode* tmp=pHead;
        rs.pop();
        while (!rs.empty())
        {
            tmp->next = rs.top();
            rs.pop();
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        return pHead;
    }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    cin.get();
    int tmp;
    ListNode* p = new ListNode;
    ListNode* pp = p;
    ListNode* pt = p;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        p->val = tmp;
        if (i == n - 1)
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
