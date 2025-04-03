Binary:
#include<iostream>
using namespace std;
int main()
{
 int g;
 cin>>g;
 if(g<=0)
 {
 cout<<"-1";
 return 0;
 }
 int a[g];
 for(int row=0;row<g;row++)
 {
 if(!(cin>>a[row]))
 {
 cout<<"Invalid input";
 return 0;
 }
 }
 bool k=false;
 for(int row=0;row<g;row++)
 {
 for(int col=row+1;col<g;col++)
 {
 if(a[row]==a[col])
 k=true;
 }

 }
 if(k)
 {
 cout<<"Duplicates Found";
 return 0;
 }
 else
 {
 cout<<"No Duplicates Found";
 return 0;
 }
}
Binary
#include using namespace std; int main() { int one; cin>>one; if(one<=0) { cout<<-1; return 0; } int arr[one]; for(int row=0;row>arr[row])) { cout<<"Invalid input"; return 0; } } int target; cin>>target; int left=0,right=one-1; while(left<=right) { int mid=(left+right)/2; if(arr[mid]==target) { cout<<"Found"; return 0; } else if(target<<"Not Found"; return 0; }
// editor4 quick sort
#include<bits/stdc++.h>
using namespace std;
void quickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int pivot=a[l];
        int i=l;
        int j=r;
        while(i<j)
        {
            i+=1;
            while(i<=r && a[i]<pivot)
            {
                i++;
            }
            while(j>=1 && a[j]>pivot)
            {
                j--;
            }
            if(i<j && i<=r)
            {
                swap(a[i],a[j]);
            }
        }
        swap(a[l],a[j]);
        quickSort(a,l,j-1);
        quickSort(a,j+1,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        if(!(cin>>a[i]))
        {
            cout<<"Invalid input";
            return 0;
        }
    }
    if(is_sorted(a,a+n))
    {
        cout<<"-1";
        return 0;
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
// editor3 sorting with print lower and upper
#include<iostream>
using namespace std;
int main()
{  int n;  cin>>n;
int a[n];
for(int i=0;i<n;i++)
{ if(!(cin>>a[i]))
{ cout<<"Invalid input";   return 0;
}
}
int b,c;
cin>>b>>c;
for(int i=0;i<n-1;i++)
{
int temp=i;
for(int j=i+1;j<n;j++)
{if(a[temp]>a[j])
{
temp=j;
}
}
swap(a[i],a[temp]);
}
for(int i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
cout<<endl;
if(c<b)
{
cout<<"-1";
return 0;}int count=0;
for(int i=0;i<n;i++)
{if(b<=a[i]&&c>=a[i])
{count++;}}
cout<<count;
}
//Max Flow Min cut Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
bool bfs(const vector<vector<int>>& residualGraph, int s, int t, vector<int>& parent) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }}   }
    return visited[t];
}
int maxFlowMinCut(vector<vector<int>>& graph, int s, int t) {
    int n = graph.size();
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;
    while (bfs(residualGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        maxFlow += pathFlow;
    }
    return maxFlow;
}
int main() {
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || m < 0) {
        cout << "Invalid input" << endl;
        return 1;
    }

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v, capacity;
        if (!(cin >> u >> v >> capacity) || u < 1 || u > n || v < 1 || v > n || capacity < 0) {
            cerr << "Invalid input" << endl;
            return 1;
        }
        graph[u - 1][v - 1] = capacity; // Adjust for 0-based indexing
    }
    int s, t;
    if (!(cin >> s >> t) || s < 1 || s > n || t < 1 || t > n || s == t) {
        cerr << "Invalid input";
        return 1;
    }
    int maxFlow = maxFlowMinCut(graph, s - 1, t - 1); // Adjust for 0-based indexing
    cout << maxFlow << endl;
    return 0;
}
Subset sum 5 10     3 7 5 10  yes 
#include<iostream>
#include<vector>
using namespace std;
bool subset(vector<int>&mat,int n,int t)
{
    if(t==0)
    {
        return true;
    }
    if(n==0)
    {
        return false;
    }
    if(mat[n-1]>t)
    {
        return subset(mat,n-1,t);
    }
    return subset(mat,n-1,t)||subset(mat,n-1,t-mat[n-1]);
}
int main()
{
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<int>mat(n);
    for(int i=0;i<n;i++)
    {
        if(!(cin>>mat[i]))
        {
            cout<<"Invalid input";
            return 0;
        }
    }
    if(subset(mat,mat.size(),t))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";  }}
// editor1 boxx moving
#include<iostream>
using namespace std;
void toh(int pl,char src,char des,char aux){
    if(pl==1){
        cout<<"Move 1"<<" Box From "<<src<<" to "<<des<<endl;
    }else{
        toh(pl-1,src,aux,des);
        cout<<"Move 1 Box From "<<src<<" to "<<des<<endl;
        toh(pl-1,aux,des,src);
    }
}int main(){
    int pl;
    if(!(cin>>pl)){
        cout<<"Invalid input";
        return 0;
    }if(pl<=0){
        cout<<"-1";
        return 0;
    }toh(pl,'S','D','A');
}
Minnum  primt the value from the minmmun range {0.2} 4
#include<bits/stdc++.h>
using namespace std;

void buildSparseTree(vector<int>& arr, vector<vector<int>>& st) {
    int n = arr.size(), m = log2(n) + 1;
    st.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) st[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int queryTable(vector<vector<int>>& st, int l, int r) {
    int j = log2(r - l + 1);
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    int n, q;
    cin >> n;
    if (n < 0) return cout << "Invalid input", 0;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    
    vector<vector<int>> st;
    buildSparseTree(arr, st);
    
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << "[" << a << ", " << b << "] " << queryTable(st, a, b) << endl;
    }
}
// editor3 minum  vlue from the ranger range 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<0){
        cout<<"Invalid input";
        return 0;
    }vector<int> sales(n);
    for(int i=0;i<n;i++){
        cin>>sales[i];
    }int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        if(l<0||r>=n||l>r){
            cout<<"Invalid input";
            return 0;
        }int min_value=*min_element(sales.begin()+l,sales.begin()+r+1);
        int sum_value=accumulate(sales.begin()+l,sales.begin()+r+1,0);
        cout<<min_value<<endl<<sum_value<<endl;
    }
}
