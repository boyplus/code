class Main{
    public static void main(String[] args){
        Solution s = new Solution();
    }
}
class ListNode {
  int val;
  ListNode next;
  ListNode() {}
  ListNode(int val) { this.val = val; }
  ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution {
    public ListNode middleNode(ListNode head) {
        int size = 0;
        ListNode now = head;
        while(now != null){
            size++;
            now = now.next;
        }
        int mid = size/2, idx = 0;
        now = head;
        while(idx < mid){
            now = now.next;
            idx++;
        }
        return now;
    }
}