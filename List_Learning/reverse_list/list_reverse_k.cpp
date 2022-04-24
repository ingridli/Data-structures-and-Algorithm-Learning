/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// 使用栈 实现k个反转
//  {1,2} k=2 反转后注意把1的next指针设为空
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1 || head == nullptr) return head;
        stack<ListNode*> rs;
        ListNode* fake = new ListNode(0);
        fake->next = head;
        auto p = fake;
        auto tmp = head;
        int m;
        while (head != nullptr)
        {
            tmp = head;
            for (int m = 1; m <= k; m++)
            {
                if (head == nullptr) break;
                rs.push(head);
                head = head->next;
            }
            if (head == nullptr && rs.size() != k)
            {
                while (tmp != nullptr)
                {
                    p->next = tmp;
                    tmp = tmp->next;
                    p = p->next;
                }
                break;
            }
            while (!rs.empty())
            {
                p->next = rs.top();
                rs.pop();
                p = p->next;
            }
        }
        p->next = nullptr;
        return fake->next;
    }
};