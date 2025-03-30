// Linear search ....
#include<iostream> 
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<-1;
        return 0;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        if(!(cin>>arr[i])){
            cout<<"Invalid input";
            return 0;
        }
       
    }
    int x;
    cin>>x;
    for(int m : arr){
        if(m==x){
            cout<<"Found";
            return 0;
        }
    }
    cout<<"Not Found";
}
