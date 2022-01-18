#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ll long long
#define ull unsigned long long
#define readi(x) int x; cin >> x
#define readll(x) ll x; cin >> x
#define reads(s) string s; cin >> s
#define rep(a, b) for (ll i = a; i < b; ++i)
#define repi(i, a, b) for (ll i = a; i < b; ++i)
#define repd(i, a, b) for (ll i = a; i > b; --i)
#define all(x) (x).begin(), (x).end()
#define init_arr readll(n); vll arr(n); rep(0, n) cin >> arr[i];
#define vprint(i) for (auto &j : i) cout << j << ' '; nl
#define mpprint(mp) for (auto &i : mp) { cout << i.ff << ' ' << i.ss << '\n'; }
#define vvprint(arr) for (auto &i : arr) { vprint(i) }
#define vvcin(n, m, arr) repi(i, 0, n) repi(j, 0, m) cin >> arr[i][j];
#define vcin(n, arr) rep(0, n) cin >> arr[i];
#define umcll unordered_map<char, ll >
#define umsll unordered_map<string, ll >
#define umll unordered_map<ll, ll >
#define print(num) cout << num << '\n';
#define mpcll map<char, ll >
#define mpsll map<string, ll >
#define mpll map<ll, ll >
#define nl cout << '\n';
#define inf (1LL << 60)
#define vll vector<ll >
#define vi vector<int >
#define vii vector<vi >
#define vs vector<string >
#define vss vector<vs >
#define vb vector<bool >
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1e9 + 7
#define ff first
#define ss second
#define N 1e6
ll power(ll x, ll n) {ll result = 1; while (n) {if (n % 2 == 1) result = result * x; n = n / 2; x = x * x;} return result;}
ll gcd(ll a, ll b) {if (!b)return a; return gcd(b, a % b);}
ll lcm(ll a , ll b) {return (a * b) / gcd(a, b);}
ll BS(ll a[], ll s, ll n, ll val) {ll mid, beg = s, end = n - 1; while (beg <= end) {mid = (beg + end) / 2; if (val == a[mid]) {break;} else if (val > a[mid]) {beg = mid + 1;} else {end = mid - 1;}} return mid;}

class ListNode
{
public:
	ll val;
	ListNode *next;
	ListNode(ll val) {
		this -> val = val;
		next = NULL;
	}
};

class linkList
{
public:
	ListNode* insert(int n)
	{
		ListNode *head = NULL, *tail = NULL;
		for (int i = 0; i < n; ++i)
		{
			int val; cin >> val;
			ListNode *newListNode = new ListNode(val);
			if (head == NULL)
			{
				head = newListNode;
				tail = newListNode;
			}
			else
			{
				tail -> next = newListNode;
				tail = tail -> next;
			}
		}
		return head;
	}

	void printList(ListNode *head)
	{
		while (head)
		{
			cout << head -> val << ' ';
			head = head -> next;
		}
	}
};

class Solution {

	ListNode* midPoint(ListNode* head)
	{
		ListNode* slow = head, *fast = head->next;
		while (fast->next)
		{
			if (fast->next->next)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			else
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		return slow;
	}

	ListNode* merge(ListNode* l, ListNode *r)
	{
		ListNode *head = NULL, *tail = NULL;
		while (l && r)
		{
			if (l->val > r->val)
			{
				if (head == NULL)
				{
					head = r;
					tail = r;
				}
				else
				{
					tail->next = r;
					tail = tail->next;
				}
				r = r->next;
			}
			else
			{
				if (head == NULL)
				{
					head = l;
					tail = l;
				}
				else
				{
					tail->next = l;
					tail = tail->next;
				}
				l = l->next;
			}
		}
		if (l)
		{
			tail->next = l;
		}
		else if (r)
		{
			tail->next = r;
		}
		return head;
	}

	ListNode* mergeSort(ListNode* l)
	{
		if (l == NULL || l->next == NULL)
			return l;
		ListNode* mid = midPoint(l);
		ListNode* midNext = mid->next;
		mid->next = NULL;
		l = mergeSort(l);
		midNext = mergeSort(midNext);
		l = merge(l, midNext);
		return l;
	}
public:
	ListNode* sortList(ListNode* temp) {
		temp = mergeSort(temp);
		return temp;
	}
};

int main() {
	fast_io;
	ll t = 1;
	// cin >> t;
	while (t--) {
		readll(n);
		linkList ob;
		ListNode *head = ob.insert(n);
		Solution s;
		// ob.printList(head);
		head = s.sortList(head);
		ob.printList(head);
	}
	return 0;
}