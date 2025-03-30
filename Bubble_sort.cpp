//Bubble sort :

#include<iostream>
using namespace std;
int main(){
    int n,c;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        if(!(cin>>arr[i])){
            cout<<"Invalid input";
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                c++;
                //swapping
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    if(c==0){
        cout<<"-1";
        return 0;
    }
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Iteration :"<<c<<endl;
}
