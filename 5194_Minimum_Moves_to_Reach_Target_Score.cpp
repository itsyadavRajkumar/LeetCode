#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
	int minMoves(int target, int maxDoubles) {
		int res = -1;
		while (target > 0)
		{
			if (maxDoubles == 0)
				return res += target;
			if (target & 1 || maxDoubles == 0)
			{
				target--;
			}
			else if (maxDoubles > 0)
			{
				int temp = target / 2;
				if (temp > 0) {
					target = temp;
					maxDoubles--;
				}
				else target--;

			}
			res++;
		}
		return res;
	}
};

int main() {

	Solution ob;
	int target; cin >> target;
	int maxDoubles; cin >> maxDoubles;
	cout << ob.minMoves(target, maxDoubles) << '\n';
	return 0;
}