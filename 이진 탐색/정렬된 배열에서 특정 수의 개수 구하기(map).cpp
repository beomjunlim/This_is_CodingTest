#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin>>n>>x;

    map<int,int> num;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num[a]++;
    }

    if(num.find(x)==num.end())
        cout<<-1;
    else
        cout<<num[x];
}

