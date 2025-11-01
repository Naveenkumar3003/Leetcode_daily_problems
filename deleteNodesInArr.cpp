class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsTodel(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=dummy;
        while(curr->next!=nullptr){
            if(numsTodel.find(curr->next->val)!=numsTodel.end()){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};
