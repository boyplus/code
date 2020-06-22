#include <vector>
#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* now = head;
        ListNode* ans = nullptr;
        ListNode* headAns = nullptr;
        stack<int> st;
        while(now != nullptr){
            st.push(now->val);
            now = now->next;
        }
        if(st.empty() == false){
            headAns = ans = new ListNode(st.top());
            st.pop();
        }
        while(st.empty() == false){
            ans->next = new ListNode(st.top());
            ans = ans->next;
            st.pop();
        }
        return headAns;
    }
};
int main(){
    Solution s;
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    // list->next->next = new ListNode(3);
    // list->next->next->next = new ListNode(4);
    ListNode* ans = s.reverseList(list);
    ListNode* head = ans;
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}