/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<int,vector<int>, greater<int>> pq;
        // priority_queue<int> pq;
        for(int i=0;i<n;i++){
            auto x=lists[i];
            while(x!=NULL){
                pq.push(x->val);
                x=x->next;
            }
        }
        ListNode* head = new ListNode();
        ListNode* prev = head;
       
        while(!pq.empty()){
            ListNode* temp = new ListNode(pq.top());
            prev->next= temp;
            prev = temp;
            pq.pop();
        }
        return head->next;

    }
};