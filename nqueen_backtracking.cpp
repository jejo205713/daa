// editor5
#include<iostream>
#include<vector>
using namespace std;
bool isSafe(vector<vector<int>>&board,int row,int col,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]==1)return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1)return false;
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]==1)return false;
    }
    return true;
}
void solve(vector<vector<int>>&board,int row,int n,vector<vector<vector<int>>>&solution){
    if(row==n){
        solution.push_back(board);
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col,n)){
            board[row][col]=1;
            solve(board,row+1,n,solution);
            board[row][col]=0;
        }
    }
}
int main()
{
    int n;
    if(!(cin>>n) || n>9){
        cout<<"Invalid input";
        return 0;
    }
    if(n==2 || n==3){
        cout<<"No solution";
        return 0;
    }
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<vector<int>>>solution;
    solve(board,0,n,solution);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(solution[0][i][j]){
                cout<<"Q";
            }
            else{
                cout<<".";
            }
            cout<<" ";
            
        }
        cout<<endl;
    }
}
