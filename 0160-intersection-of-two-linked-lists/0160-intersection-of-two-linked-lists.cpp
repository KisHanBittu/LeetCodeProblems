/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 
class Solution {
public:
    ListNode* compare(ListNode *list1,ListNode *list2,int n){
        while(n--){
            list1 = list1->next;
        }

        while(list1!=nullptr && list2!=nullptr){
            if(list1 == list2){
                return list1;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int countA = 0;
        int countB = 0;

        while(temp1!=nullptr){
            countA++;
            temp1 = temp1->next;
        }

          while(temp2!=nullptr){
            countB++;
            temp2 = temp2->next;
        }

        int diff = abs(countA - countB);
        temp1 = headA;
        temp2 = headB;

        if(countA >= countB){
            return compare(temp1,temp2,diff);
        }else{
          return compare(temp2,temp1,diff);
        }
    }
};




// Brute force
// TC - O(n)
// SC - O(n)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         map<ListNode*,int> mpp;
//         ListNode *temp = headA;

//         while(temp!=nullptr){
//             mpp[temp] = 1;
//             temp = temp->next;
//         }

//         temp = headB;
//         while(temp!=nullptr){
//             if(mpp.find(temp) != mpp.end()){
//                 return temp;
//             }
//             temp = temp->next;
//         }
//         return nullptr;
//     }
// };