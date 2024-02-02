#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int ans = 0;
    cin>>n;
    
    priority_queue<int> card;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        card.push(-num);
    }

    while(1){
        if(card.size()==1){
            cout<<-ans;
            break;
        }
        int a = card.top();
        card.pop();
        int b = card.top();
        card.pop();
        ans += (a+b);
        card.push(a+b);
    }
}

