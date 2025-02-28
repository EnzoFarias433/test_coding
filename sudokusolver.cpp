#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<int> >& grid, int r,int c, int k) {
    for(int i = 0;9 > i;i++){
        if(grid[r][i] == k){return false;}
        if(grid[i][c] == k){return false;}
    }
    for(int i = r/3*3;r/3*3 + 3 > i; i++){
        for(int j = c/3*3;c/3*3 + 3 > j;j++){
            if(grid[i][j] == k){return false;}
        }
    }
    return true;
}

bool solve(vector<vector<int> >* grid, int r = 0,int c = 0) {
    if(r == 9){return true;}
    
    if(c == 9){return solve(grid, r + 1, 0);}

    else if((*grid)[r][c] != 0){return solve(grid, r, c + 1);}
    
    else{
        
        for(int k = 1;10 > k; k++){
            
            if(is_valid(*grid,r,c,k)){
                (*grid)[r][c] = k;
                if(solve(grid, r, c+1)){
                    return true;
            }
            (*grid)[r][c] = 0;
            }

        }
        
        return false;
    }

}

int main(void) {
        vector<vector<int> > grid{
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

    if (solve(&grid)) {
        for (const auto& row : grid) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Não há solução possível para este Sudoku." << endl;
    }
    return 0;
}

