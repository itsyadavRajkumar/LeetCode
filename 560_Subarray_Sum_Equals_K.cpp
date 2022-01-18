#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size(), cnt = 0;
		unordered_map<int, int> map;
		map[0] = 1;
		vector<int> preSum(n + 1, 0);
		for (int i = 1; i < n + 1; ++i)
		{
			preSum[i] = preSum[i - 1] + nums[i - 1];
			int sum = preSum[i] - k;
			if (map.find(sum) != map.end())
				cnt += map[sum];
			map[preSum[i]]++;
		}
		return cnt;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int k; cin >> k;
	Solution ob;
	cout << ob.subarraySum(nums, k) << '\n';
	return 0;
}