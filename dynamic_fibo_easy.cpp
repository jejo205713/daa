//dynamic -> fibonaci series :
#include<iostream>
#include<vector>
using namespace std;

int fib(int n){
    if(n<0){
        cout<<"Invalid input";
        return 0;
    }
    vector<int> f(n+1);
    f[0]=0;
    if(n>=1) f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
    int n;
    cin>>n;
    if(cin.fail()||n<0 || n>=100){
        cout<<"Invalid input";
        return 0;
    }
    cout<<fib(n)<<endl;

}
