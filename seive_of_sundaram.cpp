#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n=(n-1)/2;
    vector<bool>marked(n+1,false);
    for(int i=1;i<=n;i++){
        for(int j=i;(i+j+2*i*j)<=n;j++){
            marked[i+j+2*i*j]=true;
        }
        cout<<"2 ";
        for(int i=1;i<=n;i++){
            if(!marked[i]){
                cout<<(2*i+1)<<" ";
            }
        }
        return 0;
    }
}
