#include <bits/stdc++.h>
using namespace std;

double bs(double mid, vector<vector<int>>& squares){
     
        double aArea = 0;
        double bArea = 0;

        int n = squares.size();

        for(int i = 0; i < n; i++){

            int x = squares[i][0];
            int y = squares[i][1];
            int l = squares[i][2];
            double areaSq = (double) l * l;
            int above = y + l;
            
            if(mid <= y){
                aArea = aArea + areaSq;
            } 
            else if(mid >= above){
                bArea = bArea + areaSq;
            } 
            else{

                double ah = above - mid;
                double bh = mid - y;
                aArea = aArea + l * ah;
                bArea = bArea + l * bh;

            }
        }
        return aArea - bArea;
    }

double separateSqs(vector<vector<int>>& squares) {
       
        double left = 0;
        double right = 2*1e9;
        double ans = -1.0;
        
        for(int i=0; i<100; i++){

            double mid = (left + right) / 2.0;
            double area = bs(mid, squares);

            if(area > 0){
              left = mid + 1;
            } 
            else{
               ans = mid;
               right = mid - 1;            
            }
        }

    return ans;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int row, column;
    cin >> row >> column;

    vector<vector<int>> squares(row, vector<int> (column));

    double output = separateSqs(squares);
    cout << output;
     
    return 0;

}

// INPUT :

// 2 2
// 0 0 1
// 1 1 1 

// OUPUT : 1.03878e+009