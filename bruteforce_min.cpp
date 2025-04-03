#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int minv=INT_MAX;
    int r=arr.size();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<r;i++){
        minv=min(minv,arr[i]);
    }
    cout<<minv;
}
