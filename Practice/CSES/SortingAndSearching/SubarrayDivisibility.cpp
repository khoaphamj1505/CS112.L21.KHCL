#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define down(i, a, b) for(int i=a; i>=b; i--)
#define dbg(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";
#define fi first 
#define sec second

typedef long long ll;
typedef pair<int, int> ii;
template <class T> using ordered_set = tree<T, null_type, \
less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

template <class K, class V> using ordered_map = tree<K, V, \
less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k): k-th largest element (from 0)
// order_of_key(x): the number of items that strictly smaller than x

const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
void solve(){
	int n; cin >> n;
	vt<int> arr(n+1);
	map<ll, ll> mp;
	ll cnt = 0;	

	mp[0] = 1;
	rep(i, 1, n){
		cin >> arr[i];
		if(arr[i] < 0)
			arr[i] += n*(abs(arr[i])/n + ll(abs(arr[i])%n != 0));
		arr[i] += arr[i-1];
		arr[i] %= n;
		cnt += mp[arr[i]];
		++mp[arr[i]];
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
