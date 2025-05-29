
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
          int n,k;
          cin>>n>>k;
          vector<int>v(n,0);
          for(int i=0;i<n;i++){
          cin>>v[i];
          }
          if(k==1 && !is_sorted(v.begin(),v.end()) ){
          cout<<"NO"<<endl;
          }
          else{
          cout<<"YES"<<endl;
          }
          

    }
return 0;
}