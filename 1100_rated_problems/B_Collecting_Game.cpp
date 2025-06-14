#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr<<t; }
void _print(string t) { cerr<<t; }
void _print(char t) { cerr<<t; }
void _print(double t) { cerr<<t; }
template<class T, class V> void _print(pair<T, V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T, class V> void _print(map<T, V> v);
template<class T> void _print(multiset<T> v);
template<class T, class V> void _print(pair<T, V> p) { cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}"; }
template<class T> void _print(vector<T> v) { cerr<<"[";for(T i:v){_print(i);cerr<<" ";}cerr<<"]"; }
template<class T> void _print(set<T> v) { cerr<<"[";for(T i:v){_print(i);cerr<<" ";}cerr<<"]"; }
template<class T> void _print(multiset<T> v) { cerr<<"[";for(T i:v){_print(i);cerr<<" ";}cerr<<"]"; }
template<class T, class V> void _print(map<T, V> v) { cerr<<"[";for(auto i:v){_print(i);cerr<<" ";}cerr<<"]"; }

int binExpMod(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

const int mod = 998244353;
const int N = 2e5 + 20;
vector<int> fac(N), inv(N);

void pre() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    for (int i = 0; i < N; i++) {
        inv[i] = binExpMod(fac[i], mod - 2, mod);
    }
}

int combination(int n, int k) {
    if (k > n || n < 0) return 0;
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() {
    int n;
    cin>>n;
    int mini=1e9;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        mini=min(mini,nums[i]);
    }
    //make pair with indexes to track back
    vector<pair<int,int>>v(n);
    for(int i=0;i<nums.size();i++){
        v[i]=(make_pair(nums[i],i));
    }
    sort(v.begin(),v.end());
    vector<int>prefix(n);
    prefix[0]=v[0].first;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+v[i].first;
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int j=i;
        int found=i;
        while(j<n){
            pair<int,int>temp={prefix[j]+1,INT_MIN};
            int index=lower_bound(v.begin(),v.end(),temp)-v.begin();
            index--;
            if(index==j)break;
            found+=index-j;
            j=index;
        }
        ans[v[i].second]=found;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    pre();
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}