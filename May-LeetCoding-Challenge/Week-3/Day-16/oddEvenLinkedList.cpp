/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode *evenNode, *even, *odd;
        
        evenNode = head->next;
        odd = head;
        even=evenNode;
        
        while(even != NULL && even->next!=NULL){
            odd->next=  even->next;
            odd = even->next;
            even->next = odd->next;
            even = odd->next;
        }
        odd->next = evenNode;
        return head;
    }
};
