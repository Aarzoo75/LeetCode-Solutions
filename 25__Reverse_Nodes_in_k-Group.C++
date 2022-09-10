


class Solution {

	ListNode* Reverse(ListNode* head){
		if(head == NULL or head->next == NULL) return head;
		ListNode* curr = head, *prev = NULL , *next = head->next;
		while(next != NULL){
			curr->next = prev;
			prev = curr;
			curr = next;
			next = next->next;
		}
		curr->next = prev;
		return curr;
	}

	ListNode* solve(ListNode* head , int k){
		if(head == NULL or head->next == NULL) return head;
		ListNode* curr = head;
		for(int i = 1 ; i < k and curr != NULL ; curr = curr->next , i++);
		if(curr == NULL) return head;
		ListNode* temp = curr->next;
		curr->next = NULL;
		ListNode* a = Reverse(head);
		head->next = solve(temp,k);
		return a;
	}

public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(head == NULL or head->next == NULL or k <= 1) return head;

		ListNode* ans = solve(head,k);
		return ans;

	}
};