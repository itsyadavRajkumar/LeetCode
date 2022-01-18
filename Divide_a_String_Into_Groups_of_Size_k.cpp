#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {
		int cnt = 0;
		int n = s.size();
		string temp = "";
		vector<string> res;
		for (int i = 0; i < n; ++i)
		{
			temp.push_back(s[i]);
			cnt++;
			if (cnt == k)
			{
				res.push_back(temp);
				temp = "";
				cnt = 0;
			}
		}
		while (cnt != k && cnt != 0)
		{
			temp.push_back(fill);
			cnt++;
		}
		if (temp != "")
			res.push_back(temp);
		return res;
	}
};

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;
	char fill; cin >> fill;
	Solution ob;
	vector<string> res = ob.divideString(s, k, fill);
	for (auto it : res)
		cout << it << " ";

	return 0;
}