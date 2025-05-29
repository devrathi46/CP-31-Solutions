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
    int n,k;
    cin>>n>>k;
    vector<int>a(n,0);
    vector<int>b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    bool check=1;
    for(int i=0;i<n;i++){
        if(b[i]!=-1){
            check=0;
        }
    }
    if(check){
        int maxi=-1e9;
        int mini=1e9;
        for(int i=0;i<n;i++){
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
        }
        cout<<(mini+k-maxi+1)<<endl;
        return;
    }

    int prev_sum=-1;
    int sum=-1;
    for(int i=0;i<n;i++){
        if(b[i]!=-1){
            if(prev_sum==-1){
                sum=a[i]+b[i];
                prev_sum=sum;
            }
            else{
                sum=a[i]+b[i];
                if(prev_sum==sum)continue;
                else{
                    cout<<0<<endl;
                    return;
                }
            }
        }
    }
    bool flag=1;
    int count=0;
    for(int i=0;i<n;i++){
        if(sum-a[i]>=0 && sum-a[i]<=k)continue;
        else {
            flag=0;
            break;
        }
    }
    if(flag){
        count++;
        cout<<count<<endl;
    }
    else cout<<0<<endl;  
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