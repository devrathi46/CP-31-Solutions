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
    vector<vector<int> >mat(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int ans=0;
    //main diagonal
    int mini=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
            mini=min(mini,mat[i][j]);
        }
    }
    if(mini<0)ans+=abs(mini);
    //lower triangle
    for(int k=1;k<n;k++){
        mini=1e9;
        int j=0;
        int i=k;
        while(i<n && j<n){
            mini=min(mini,mat[i][j]);
            i++;
            j++;
        }
        if(mini<0)ans+=abs(mini);
    }
    //upper triangle
    for(int k=1;k<n;k++){
        mini=1e9;
        int i=0;
        int j=k;
        while(i<n && j<n){
            mini=min(mini,mat[i][j]);
            i++;
            j++;
        }
        if(mini<0)ans+=abs(mini);
    }
    cout<<ans<<endl;
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