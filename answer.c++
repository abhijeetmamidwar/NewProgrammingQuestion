#include<iostream>
#include<vector>
using namespace std;

int main(){

    int R = 6, C = 6, n = 1;
    int TotalElements = R * C;
    // vector<vector<int>> M(R, vector<int>(C, 0));
    // for(int i = 0; i < R; i++)
    //     for(int j = 0; j < C; j++){
    //         M[i][j] = n;
    //         n += 1;
    //     }

    vector<vector<int>> M = {{1,6,15,16,7,2}, 
                            {5,14,26,27,17,8}, 
                            {13,25,33,34,28,18}, 
                            {24,32,36,35,29,19}, 
                            {12,23,31,303,20,9}, 
                            {4,11,22,21,10,3}};

    vector<vector<int>> points = {{0, 0}, {0, C - 1}, {R - 1, C - 1}, {R - 1, 0}};
    vector<vector<int>> nextItr = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<vector<int>> shiftInside = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> dir = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

    vector<int> ans;
    n = 0;
    while(n < TotalElements){
        int fPr = points[0][0], fPc = points[0][1];
        for(int i = 0; i < 4; i++){
            int sr = points[i][0], sc = points[i][1];
            while(sr >= 0 && sr < R && sc >= 0 && sc < C && M[sr][sc] != -1){
                ans.push_back(M[sr][sc]);
                n += 1;
                M[sr][sc] = -1;
                sr += dir[i][0], sc += dir[i][1];
            }
            sr -= dir[i][0], sc -= dir[i][1];
            if(i == 3){
                fPr = sr, fPc = sc;
            }
            if(n == TotalElements)break;
        }
        if(n == TotalElements)break;
        else if(fPr - 1 == points[0][0]){
            for(int i = 0; i < 4; i++){
                points[i][0] += shiftInside[i][0];
                points[i][1] += shiftInside[i][1];
            }
        }
        else{
            for(int i = 0; i < 4; i++){
                points[i][0] += nextItr[i][0];
                points[i][1] += nextItr[i][1];
            }
        }
        
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
