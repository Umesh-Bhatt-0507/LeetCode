// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode dummy;
//         ListNode *curr=&dummy;
//         int carry=0;
//         while(l1!=nullptr || l2!=nullptr || carry!=0){
//             int sum=carry;
//             if(l1!=nullptr){
//                 sum+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2!=nullptr){
//                 sum+=l2->val;
//                 l2=l2->next;
//             }  
//             carry=sum/10;
//             curr->next=new  ListNode(sum%10);
//             curr=curr->next;
//         }
//         return dummy.next;
//     }
// };

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newNode=new ListNode(0);
        ListNode* curr=newNode;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL || carry){
            int sum=carry;
            if(temp1!=NULL){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            carry=sum/10;
            curr->next= new ListNode(sum%10);
            curr=curr->next;
        }
        return newNode->next;
    }
};