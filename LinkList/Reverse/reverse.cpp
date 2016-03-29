#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* now = head;
    ListNode* next = nullptr;
    while (now) {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    return pre;
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i < 10; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }
    ListNode* newHead = reverse(head);
    ListNode* iter = newHead;
    while (iter) {
        cout << iter->val << "  ";
        iter = iter->next;
    }
    cout << endl;
    return 0;
}
