#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	void sort(ListNode* head) {
		for (ListNode* i = head; i != NULL; i = i->next) {
			for (ListNode* j = i->next; j != NULL; j = j->next) {
				if (i->val > j->val) {
					i->val = (i->val) ^ (j->val);
					j->val = (i->val) ^ (j->val);
					i->val = (i->val) ^ (j->val);
				}
			}
		}
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = NULL;
		if (!lists.size())
			return head;
		int n = lists.size();
		head = lists[0];
		ListNode* pre = NULL;
		for (int i = 0; i < n - 1; ++i)
		{
			ListNode* temp = lists[i];
			while (temp) {
				pre = temp;
				temp = temp->next;
			}
			if (lists[i + 1] != NULL && pre != NULL)
				pre->next = lists[i + 1];
			else if (lists[i + 1] != NULL && pre == NULL)
				head = lists[i + 1];
		}

		sort(head);
		return head;
	}
};
int main() {

	return 0;
}