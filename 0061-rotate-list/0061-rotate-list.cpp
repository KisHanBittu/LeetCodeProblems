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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 1;
        int cnt = 1;
        ListNode* tail = head;
        ListNode* temp = head;

        if (head == nullptr || head->next == nullptr)
            return head;

        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }

        if (k % len == 0) {
            return head;
        }

        k = k % len;

        tail->next = head;

        while (temp->next != nullptr) {
            if (cnt == len - k) {
                head = temp->next;
                temp->next = nullptr;
                break;
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};

//  // Brute force(TLE)
//  // TC = O(n*k)
//  // SC = O(1)
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         ListNode* prev = head;
//         ListNode* temp;
//         if(head == nullptr || head->next == nullptr){
//             return head;
//         }
//         for(int i = 0; i< k;i++){
//             prev = head;
//             while(prev->next->next!=nullptr){
//                 prev = prev->next;
//             }
//             temp = prev->next;
//             temp->next = head;
//             prev->next = nullptr;
//             head = temp;
//         }
//         return head;
//     }
// };