#include <bits/stdc++.h>
using namespace std;

bool powerTwo(int n){

  if(n<=0){
    cout << "false";
  }


  if((n & (n-1)) == 0){
    cout << "true";
  }
  
  else{
    cout << "false";
  }

}
int main(){

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  cin >> n;

  powerTwo(n);

  return 0;

}