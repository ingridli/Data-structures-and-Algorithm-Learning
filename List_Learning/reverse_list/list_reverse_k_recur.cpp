/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public: ListNode* reverseKGroup(ListNode* head, int k) {
    //±ß½çÌõ¼þÅÐ¶Ï
    if (head == nullptr || head->next == nullptr || k == 1)
        return head;
    auto fake = new ListNode(0);
    fake->next = head;
    auto tmp = fake;
    reverse(tmp, k);
    return fake->next;
}
private: void reverse(ListNode* head, int k)
{
    auto tmp = head->next;
    for (int i = 0; i < k; i++)
    {
        if (tmp == nullptr) return;
        tmp = tmp->next;
    }
    auto tmp1 = head->next;
    stack<ListNode*> rs;
    for (int i = 0; i < k; i++)
    {
        rs.push(tmp1);
        tmp1 = tmp1->next;
    }
    while (!rs.empty())
    {
        head->next = rs.top();
        rs.pop();
        head = head->next;
    }
    if (tmp == nullptr)
    {
        head->next = nullptr;
        return;
    }
    head->next = tmp;
    reverse(head, k);
}

};