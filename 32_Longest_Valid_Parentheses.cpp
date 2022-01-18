// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
public:
    int longestValidParentheses(string s) {
        // code here
        stack<char> ch;
        stack<int> index;
        index.push(-1);
        int n = s.size(), mx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                ch.push(s[i]);
                index.push(i);
            }
            else
            {
                if (!ch.empty() && ch.top() == '(')
                {
                    ch.pop();
                    index.pop();
                    mx = max(mx, i - index.top());
                }
                else
                {
                    index.push(i);
                }
            }
        }
        return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.longestValidParentheses(S) << endl;
    }
    return 0;
}
// } Driver Code Ends