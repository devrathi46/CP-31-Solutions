#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    char s[n];
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
    int flag=1;
    int count=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='.')
      {
         count++;
      }
      if(i>0 && i<n-1)
      {
        if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.')
        {
          cout<<2<<endl;
          flag=0;
          break;
        }
      }
  }
  if(flag)cout<<count<<endl;
  
  }
}