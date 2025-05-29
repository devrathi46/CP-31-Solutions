#include<iostream>
using namespace std;


bool even(int num){
    if(num%2==0){
      return 1;
    }
    return 0;
  }
  bool odd(int num){
    if(num%2!=0){
      return 1;
    }
    else{
      return 0;
    }
  }

int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int ops=0;
    for(int i=0;i<n-1;i++){
      if(odd(arr[i]) && odd(arr[i+1]) || even(arr[i]) && even(arr[i+1])){
        ops++;
      }
    }
    cout<<ops<<endl;

  }
}
