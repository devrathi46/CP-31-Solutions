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


void solve() {
    string a;
    cin>>a;
    string b;
    cin>>b;

   int n=a.length();
   int m=b.length();
   int ans=0;

   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]= 0;
            }
        }
    }
    cout<<a.length()+b.length()-2*ans<<endl; 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}