#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int x=0;
  while(n--){
    
   string statement;
   cin>>statement;
   if(statement.find("++")!=string::npos){
    x++;
   }
   else if(statement.find("--")!=string::npos){
    x--;
   }
   
  }
  cout<<x<<endl;
}