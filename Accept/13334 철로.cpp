#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, d, ans;
vector< pair<int,int> > v;
int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    int a,b;
    scanf("%d %d", &a, &b);

    v.push_back(make_pair( max(a,b), min(a,b) ));
  }
  scanf("%d", &d);

  sort(v.begin(), v.end());

  priority_queue< int, vector<int>, greater<int> > pq;

  for(int i=0; i < v.size(); i++) {
    if (v[i].first - v[i].second > d)
      continue;

    while (!pq.empty() && v[i].first - d > pq.top()) {
      pq.pop();
    }
    pq.push(v[i].second);
    ans = max(ans, (int)pq.size());
  }
  printf("%d\n", ans);
  return 0;
}