#include <vector>
#include <iostream>
#include <cstdlib>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* now = head;
        if(head == nullptr){
            return head;
        }
        while(now->next != nullptr){
            int tempVal = now->val;
            now->val = now->next->val;
            now->next->val = tempVal;
            if(now->next->next != nullptr){
                now = now->next->next;    
            } else{
                break;
            }
        }
        return head;
    }
};
int main(){
	Solution s;
    return 0;
}