#include <bits/stdc++.h>
using namespace std;

int powerExpo(int x, int n){

   int ans = 1;
   for(int i=1; i<=n; i++){
      ans = ans*x;
   }
   return ans;
}
int main(){

   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif

   int  x, n;
   cin >> x >> n;

   int result = powerExpo(x, n);
   cout << result;
}