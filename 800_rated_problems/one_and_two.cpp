#include<iostream>
#include<vector>
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
    int count=0;
    for(int i=0;i<n;i++){
      if(v[i]==2)count++;
    }
    if(count%2==0){
      int count1=0;
      for(int i=0;i<n;i++){
        if(v[i]==2){
          count1++;
        }
        if(count1==count/2){
          cout<<i+1<<endl;
          break;
        }
      }
    }
    else{
      cout<<-1<<endl;
    }
  }
}

