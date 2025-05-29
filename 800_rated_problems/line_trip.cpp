#include<iostream>

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,x;
    cin>>n>>x;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    vector<int>ans;
    int prev=0;
    for(int i=0;i<n;i++){
      ans.push_back(v[i]-prev);
      prev=v[i];
    }
    ans.push_back((x-v[n-1])*2);
    int maxi=*max_element(ans.begin(),ans.end());
    cout<<maxi<<endl;
  }

}