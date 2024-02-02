#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin>>n>>k;

    vector<int> a;
    vector<int> b;
    int sum = 0;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        sum += num;
        a.push_back(num);
    }

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        b.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);

    for(int i=0; i<k; i++){
        if(a[i]<b[i]){
            sum -= a[i];
            sum += b[i];
        }
    }
    
    cout<<sum;
}
