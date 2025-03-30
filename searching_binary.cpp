// binary search 
#include<iostream>
#include<vector>
using namespace std;
int bs(vector<int>& arr,int k){
    int l=0,r=arr.size()-1;
    
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==k)return 1;
        else if(arr[mid]<k)l=mid+1;
        else r=mid-1;
    }
    return 0;
    
}
int main(){
    int n;
    cin>>n;
    if(n<=0 || n>=500){
        cout<<"-1";
        return 0;
    }
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        if(!(cin>>arr[i])){
            cout<<"Invalid input";
            return 0;
        }
    }
    int k=0;
    cin>>k;
    int res=0;
    res=bs(arr,k);
    if(res==1){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}
