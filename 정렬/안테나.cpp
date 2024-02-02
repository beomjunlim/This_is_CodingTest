#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> house(n);

    for(int i=0; i<n; i++){
        cin>>house[i];
    }

    sort(house.begin(), house.end());

    int num = house[(n-1)/2];
    cout<<num;
}
