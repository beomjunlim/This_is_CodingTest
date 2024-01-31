#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX 11
int n;
int arr[MAX];
int max_sum = INT_MIN;
int min_sum = INT_MAX;

void dfs(int index, int ans, int plus, int minus, int product, int divide){
    if(index==n){
        max_sum = max(max_sum, ans);
        min_sum = min(min_sum, ans);
    }

    if(plus>0){
        int num = ans + arr[index];
        dfs(index+1, num, plus-1, minus, product, divide);
    }
    if(minus>0){
        int num = ans - arr[index];
        dfs(index+1, num, plus, minus-1, product, divide);
    }
    if(product>0){
        int num = ans * arr[index];
        dfs(index+1, num, plus, minus, product - 1, divide);
    }
    if(divide>0){
        int num = ans / arr[index];
        dfs(index+1, num, plus, minus, product, divide-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int plus, minus, product, divide;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }    

    cin>>plus>>minus>>product>>divide;

    dfs(1,arr[0],plus,minus,product,divide);
    
    cout<<max_sum<<'\n';
    cout<<min_sum<<'\n';
}
