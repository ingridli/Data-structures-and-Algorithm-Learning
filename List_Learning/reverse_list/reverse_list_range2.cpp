#include<iostream>
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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if (m == n) return head;
        ListNode fake;
        fake.next = head;
        head = &fake;
        ListNode* m1 = head, * n1 = nullptr, * tmp = head;
        stack<ListNode*> rs;
        for (int i = 0; i <= m; i++)
        {
            if (i == m)
            {
                for (int j = i; j <= n; j++)
                {
                    rs.push(tmp);
                    tmp = tmp->next;
                }
                n1 = tmp;
                break;
            }
            m1 = tmp;
            tmp = tmp->next;
        }
            while (!rs.empty())
            {
                m1->next = rs.top();
                rs.pop();
                m1 = m1->next;
            }
            m1->next = n1;
            head = head->next;
        return head;
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
    int m1, n1;
    cin >> m1 >> n1;
    ListNode* p2 = s.reverseBetween(pt, m1, n1);
    for (int i = 0; i < n; i++)
    {
        cout << p2->val << ' ';
        p2 = p2->next;
    }
    return 0;
}