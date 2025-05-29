#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
      cin>>v[i];
    }
    unordered_map<int,int>mymap;
    for(int i=0;i<v.size();i++){
      mymap[v[i]]++;
    }
    if(mymap.size()<=2)
    {
      cout<<"NO"<<endl;
    }
    else{
     vector<int>ans;
     for(auto it:mymap){
      ans.push_back(it.second);
     }
      if(abs(ans[1]-ans[0])==1)
      {
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
  

  }
}