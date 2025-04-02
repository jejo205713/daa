#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=0||n>=10||n<=-10){
        cout<<"-1";
        return 0;
    }
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        if(!(cin>>arr[i])||arr[i]>18||arr[i]<3){
            cout<<"Invalid input";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int j:arr){
        cout<<j<<" ";
    }
}
