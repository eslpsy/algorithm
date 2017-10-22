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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryFlag = 0;
        ListNode* l3 = new ListNode(0);
    	ListNode* result = l3;
    	
        while (l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = x + y + carryFlag;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            carryFlag = sum / 10;
            if (l1 != NULL)  l1 = l1->next;
            if (l2 != NULL)  l2 = l2->next;
        }
        if (carryFlag)
        {
            l3->next = new ListNode(carryFlag);
        }
	    
    	return result->next;
    }
};