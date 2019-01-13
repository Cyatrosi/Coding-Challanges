#include<iostream>
using namespace std;
#define N 5
#define M 5
bool isValidIndex(int i,int j){
    if(i>=0 && i<N && j>=0 && j<M)
        return true;
    return false;
}
void applyBfs(int grid[N][M],int i,int j){
    if(!isValidIndex(i,j))  // Index out of Grid
        return;
    if(grid[i][j] == 0)  // Stepped on a blocked cell
        return;
    grid[i][j] = 0;
    // Go Top
    applyBfs(grid,i-1,j);
    // Go Down
    applyBfs(grid,i+1,j);
    // Go Left
    applyBfs(grid,i,j-1);
    // Go Right
    applyBfs(grid,i,j+1);
}
int findCookieCount(int grid[N][M]){
    int CookieCnt = 0;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            if(grid[i][j] == 1){
                applyBfs(grid,i,j);
                ++CookieCnt;
            }
    return CookieCnt;
}
int main(){
int grid[N][M] = {
    {1,0,0,1,0},
    {1,0,1,0,0},
    {0,0,1,0,1},
    {1,0,1,0,1},
    {1,0,1,1,0}
};
cout<<findCookieCount(grid);
return 0;
}
