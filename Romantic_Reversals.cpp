// #include <bits/stdc++.h>
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define readi(x) int x; cin >> x
// #define readll(x) ll x; cin >> x
// #define reads(s) string s; cin >> s
// #define rep(a, b) for (ll i = a; i < b; ++i)
// #define repi(i, a, b) for (ll i = a; i < b; ++i)
// #define repd(i, a, b) for (ll i = a; i >= b; --i)
// #define all(x) (x).begin(), (x).end()
// #define init_arr readll(n); vll arr(n); rep(0, n) cin >> arr[i];
// #define vprint(i) for (auto &j : i) cout << j << ' '; nl
// #define mpprint(mp) for (auto &i : mp) { cout << i.ff << ' ' << i.ss << '\n'; }
// #define vvprint(arr) for (auto &i : arr) { vprint(i) }
// #define vvcin(n, m, arr) repi(i, 0, n) repi(j, 0, m) cin >> arr[i][j];
// #define vcin(n, arr) rep(0, n) cin >> arr[i];
// #define umcll unordered_map<char, ll >
// #define umsll unordered_map<string, ll >
// #define umll unordered_map<ll, ll >
// #define print(num) cout << num << '\n';
// #define mpcll map<char, ll >
// #define mpsll map<string, ll >
// #define mpll map<ll, ll >
// #define nl cout << '\n';
// #define inf (1LL << 60)
// #define vll vector<ll >
// #define vi vector<int >
// #define vii vector<vi >
// #define vs vector<string >
// #define vss vector<vs >
// #define vb vector<bool >
// #define pb push_back
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define mod 1e9 + 7
// #define ff first
// #define ss second
// #define N 1e6

// string solve(ll k, string s) {
// 	ll n = s.size();
// 	repd(i, k, 0)
// 	{
// 		reverse(s.begin(), s.begin() + i);
// 	}
// 	return s;
// }

// int main() {
// 	fast_io;
// 	ll t = 1;
// 	cin >> t;
// 	while (t--) {
// 		ll n, k; cin >> n >> k;
// 		reads(s);
// 		cout << solve(k, s) << '\n';
// 	}
// 	return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define pi 3.141592653589793238
#define vr(v) v.begin(),v.end()
#define rsv(v) v.end(),v.begin()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Asquare cout.tie(NULL);
using namespace std;
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a / gcd(a, b) * b);}
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {return (a.second < b.second);}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {return (a.second > b.second);}
void printarr(ll arr[], ll n) {fl(i, n) cout << arr[i] << " "; cout << "\n";}
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}
ll binaryToDecimal(string n) {string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base; base = base * 2;} return dec_value;}
bool isPrime(int n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(int n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}
ll moduloMultiplication(ll a, ll b, ll mod) {ll res = 0; a %= mod; while (b) {if (b & 1)res = (res + a) % mod; b >>= 1;} return res;}
ll powermod(ll x, ll y, ll p) {ll res = 1; x = x % p; if (x == 0) return 0; while (y > 0) {if (y & 1)res = (res * x) % p; y = y >> 1; x = (x * x) % p;} return res;}
vector<int> primees(10000000, 1); vector<int> anses(10000000, 0);
ll mx = LONG_LONG_MIN; ll mn = LONG_LONG_MAX;
void isPrimes() {int c = 0; for (int p = 2; p * p <= 10000000; p++)if (primees[p] == 1)for (int i = p * 2; i <= 10000000; i += p) {primees[i] = 0;} for (int p = 2; p <= 10000000; p++) {anses[p] = anses[p - 1] + primees[p];}}
ll productOfSubsetSums(ll arr[], ll n, ll mod) {ll ans = 1; for (int i = 0; i < n; ++i )ans = ((ans % mod) * ((arr[i] + 1) % mod)) % mod; return ans - 1;}
typedef pair<ll, ll> pll;
//Code by Abhinav Awasthi
//Language C++
//Practice->Success
void asquare()
{
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string snew = "";
	string sn = s.substr(0, k);
	ll in1 = 0;
	ll in2 = k - 1;
	ll in = k - 1;
	if (k == 1)
		cout << s << "\n";
	else
	{
		while (in1 <= in2)
		{
			if (in1 == in2)
			{	s[in--] = sn[in1];
				in1++;
			}
			else
			{	s[in--] = sn[in1];
				in1++;
				s[in--] = sn[in2];
				in2--;
			}
		}
		cout << s << "\n";
	}
}
int main()
{
	Code By Asquare
#ifdef AbhinavAwasthi
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
	ll t;
	cin >> t;
	while (t--)
	{
		asquare();
	}
	// asquare();
	return 0;
}