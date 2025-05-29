#include<iostream>
#include<vector>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    //input 
    int n;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
      cin>>b[i];
    }
      if(n==1){
        cout<<"1"<<endl;
        cout<<b[0]<<endl;
      
    }

   else{
      vector<int>v;
      v.push_back(b[0]);
      for(int i=1;i<n;i++){
        if(b[i-1]<=b[i]){
          v.push_back(b[i]);
          continue;
        }
        else{
          v.push_back(b[i]);
          v.push_back(b[i]);
        }

      }
      cout<<v.size()<<endl;
      for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
      }
   }
    


  }
}