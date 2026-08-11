/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        unordered_set<ListNode*> store;
        ListNode *temp=head;
        while(temp->next!=NULL){
            store.insert(temp);
            if(store.count(temp->next)){
                return temp->next;
            }
            temp=temp->next;
        }
        return NULL;
    }
};