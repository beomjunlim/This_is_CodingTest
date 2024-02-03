#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int answer = -1;
    cin>>n;

    map<int,int> num;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num[i] = a;
    }

    for(auto i : num){
        if(i.first==i.second){
            answer = i.first;
        }
    }

    cout<<answer;
}
