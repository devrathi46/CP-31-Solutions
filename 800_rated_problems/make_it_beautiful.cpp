#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    if(v[0]==v[n-1]){
      cout<<"No"<<endl;
    }
    else{
      cout<<"Yes"<<endl;
      cout<<v[n-1]<<" "<<v[0]<<" ";
      for(int i=1;i<n-1;i++){
        cout<<v[i]<<" ";
      }
      cout<<endl;
    }
  
  }
}