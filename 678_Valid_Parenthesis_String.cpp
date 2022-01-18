#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	bool checkValidString(string s) {
		stack<int> st;
		stack<int> point;
		int n = s.length();
		for (int i = 0; i < n; ++i)
		{
			// cout << i << ":" << s[i] << endl;
			if (s[i] == '*')
				point.push(i);
			else if (s[i] == '(')
				st.push(i);
			else
			{
				if (!st.empty())
					st.pop();
				else if (!point.empty())
				{
					point.pop();
				}
				else
					return false;
			}
		}
		while ((!st.empty() && !point.empty()) && (st.top() < point.top()))
		{
			point.pop(), st.pop();
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};

int main() {
	string s; cin >> s;
	Solution ob;
	cout << ob.checkValidString(s) << '\n';
	return 0;
}