// Dynamic LCS HARD PROGRAM :
#include<iostream>
#include<vector>
using namespace std;
bool isValidDna(string &s){
    for(char c : s){
        if(c!='A'&&c!='C'&&c!='G'&&c!='T')
        return false;
    }
    return true;
}

int lcs(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            }
            
        }

    return dp[m][n];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(!isValidDna(s1)||!isValidDna(s2)){
        cout<<"Invalid input";
        return 0;
    }
    cout<<lcs(s1,s2);
    
}
