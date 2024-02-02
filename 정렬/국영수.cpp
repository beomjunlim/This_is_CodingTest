#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student{
    string name;
    int korea;
    int english;
    int math;
};

bool cmp(Student a, Student b){
    if(a.korea==b.korea&&a.english==b.english&&a.math==b.math){
        return a.name < b.name;
    }
    else if(a.korea==b.korea&&a.english==b.english&&a.math!=b.math){
        return a.math > b.math;
    }
    else if(a.korea==b.korea&&a.english!=b.english){
        return a.english < b.english;
    }
    else{
        return a.korea > b.korea;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<Student> student;

    for(int i=0; i<n; i++){
        string s;
        int k;
        int e;
        int m;
        cin>>s>>k>>e>>m;
        student.push_back({s,k,e,m});
    }

    sort(student.begin(), student.end(), cmp);

    for(int i=0; i<n; i++){
        cout<<student[i].name<<'\n';
    }
}
