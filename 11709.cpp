#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define MAX 100010

using namespace std;

vector <int> edge[MAX];
int num, len, ans, caseNum, stkLen, stkID, findID;
int dfn[MAX], parent[MAX], stk[MAX];
bool inStk[MAX], visited[MAX];
char name[50], a[50], b[50];

void init();
int dfs(int cur);

int main() {
  int i, x, y;
  while(scanf("%d %d", &num, &len) != EOF) {
    if(num == 0 && len == 0) {
      break;
    }
    
    init();
    getchar();

    map<string, int> Map;

    for (i = 0; i < num; ++i) {
      gets(name);
      Map[name] = i;
    }

    for (i = 0; i < len; ++i) {
      gets(a);
      gets(b);
      
      edge[Map[a]].push_back(Map[b]);
    }

    for (i = 0; i < num; ++i) {
      if (!visited[i]) {
        findID = 0;
        stkID = -1;
        dfs(i);
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}

void init() {
  int i;

  ans = 0;

  for (i = 0; i <= num; ++i) {
    edge[i].clear();
    dfn[i] = 0;
    visited[i] = false;
    inStk[i] = false;
    parent[i] = i;
  }
}

int dfs(int cur) {
  int i, low;

  visited[cur] = true;
  inStk[cur] = true;

  stk[++stkID] = cur;
  dfn[cur] = ++findID;
  low = dfn[cur];

  vector<int>::iterator it;

  for(it = edge[cur].begin(); it != edge[cur].end(); ++it) {
    if(!visited[*it]) {
        low = min(low, dfs(*it));
    }
    if(inStk[*it]) {
        low = min(low, dfn[*it]);
    }
  }
  if(low == dfn[cur]) {
    inStk[stk[stkID]] = false;
    while(stk[stkID--] != cur) {
      inStk[stk[stkID]] = false;
    }
    ans++;
  }
  return low;
}