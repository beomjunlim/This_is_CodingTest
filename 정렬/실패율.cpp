#include <string>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;

bool cmp(pair<int,double> a, pair<int,double> b){
    if(a.second==b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
  vector<int> answer;
  vector<pair<int, double>> index;
  int people = stages.size();
    
  sort(stages.begin(), stages.end());
  
  map<int,int> pro;
  
  for(int i=1; i<=N; i++){
      pro[i] = 0;
  }
    
  for(int i=0; i<people; i++){
      pro[stages[i]]++;
  }
    
  for(auto &i : pro){
      double num = double(i.second)/people;
      int idx = i.first;
     
      if(idx<=N&&people!=0)
        index.push_back({idx,num});
      else if(idx<=N&&people==0)
        index.push_back({idx,0});
      people -= i.second;
  }
  
  sort(index.begin(), index.end(), cmp);

  for(int i=0; i<index.size(); i++){
      answer.push_back(index[i].first);
  }

  return answer;
}
