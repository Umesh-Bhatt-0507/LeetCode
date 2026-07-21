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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *cur=slow;
        ListNode *pre=NULL;
        ListNode *nex=slow->next;
        while(nex){
            cur=nex;
            nex=nex->next;
            cur->next=pre;
            pre=cur;
        }
        ListNode *c1=head;
        ListNode *c2=pre;
        while(c2){
            if(c2->val !=c1->val){
                return false;
            }
            c1=c1->next;
            c2=c2->next;
        }
        return true;


        // ListNode *temp=head;
        // stack<int> store;
        // while(temp!=NULL){
        //     store.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     if(temp->val!=store.top()){
        //         return false;
        //     }
        //     store.pop();
        //     temp=temp->next;
        // }
        return true;
    }
};