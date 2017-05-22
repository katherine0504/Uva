#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define MAX 1010

using namespace std;

vector <int> edge[MAX];
vector <int> ans[MAX];
int num, len, a, b, findID, caseNum = 0;
int dfn[MAX], low[MAX];
bool visited[MAX];

void init();
int dfs(int cur, int parent);

int main() {
  int i, j;
  
  while(scanf("%d%d", &num, &len) != EOF) {
  	if (num == 0 && len == 0) {
  		break;
  	}
    
    init();

    for (i = 1; i <= len; ++i) {
      scanf("%d %d", &a, &b);
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
		
		printf("%d\n\n", ++caseNum);
		
		for (i = 1; i <= num; ++i) {
      if (!visited[i]) {
        findID = 0;
        dfs(i, -1);
      }
    }

    for(i = 1; i <= num; ++i) {
      sort(ans[i].begin(), ans[i].end());
      vector<int>::iterator it;
      for (it = ans[i].begin(); it != ans[i].end(); ++it) {
        printf("%d %d\n", i, *it);
      }
    }
    printf("#\n");
  }
  return 0;
}

void init() {
  int i;

  for (i = 1; i <= num; ++i) {
    edge[i].clear();
    ans[i].clear();
    visited[i] = false;
  }
}

int dfs(int cur, int parent) {
  int i, low, nxt;

  visited[cur] = true;
  dfn[cur] = ++findID;
  low = dfn[cur];
  
  for (i = 0; i < edge[cur].size() ; ++i) {
    nxt = edge[cur][i];

    if(!visited[nxt]) {
      int bridge = dfs(nxt, cur);
      
      if(bridge > dfn[cur]) {
        ans[cur].push_back(nxt);
        ans[nxt].push_back(cur);
      } else {
        ans[cur].push_back(nxt);
      }
      low = min(low, bridge);
    } else {
      if (nxt != parent) {
        if (dfn[cur] >= dfn[nxt]) {
          ans[cur].push_back(nxt);
        }
        low = min(low, nxt);
      }
    }
  }
  return low;
}