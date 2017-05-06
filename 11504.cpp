#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 100010

using namespace std;

vector <int> edge[MAX];
int num, len, ans, a, b, caseNum, stkLen, stkID, findID;
int dfn[MAX], parent[MAX], IDX[MAX], stk[MAX];
bool inStk[MAX], visited[MAX];

void init();
int dfs(int cur);

int main() {
  int i, j, k;
  scanf("%d", &caseNum);
  
  for (i = 0; i < caseNum; ++i) {
    scanf("%d %d", &num, &len);
    
    init();

    for (j = 1; j <= len; ++j) {
      scanf("%d %d", &a, &b);
      edge[a].push_back(b);
    }

    for (j = 1; j <= num; ++j) {
      if (!visited[j]) {
        findID = 0;
        stkID = -1;
        dfs(j);
      }
    }

    for (j = 1; j <= num; ++j) {
      vector<int>::iterator it;
      for (it = edge[j].begin(); it != edge[j].end(); ++it) {
        if (parent[*it] != *it) {
          IDX[*it]++;
        }
        if (parent[j] != parent[*it]) {
          IDX[parent[*it]]++;
        }
      }
    }

    for (j = 1; j <= num; ++j) {
      if(!IDX[j] && parent[j] == j) {
        ans++;
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}

void init() {
  int i;

  ans = 0;

  memset(IDX, 0, MAX);

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
    parent[stk[stkID]] = cur;
    inStk[stk[stkID]] = false;
    
    while(stk[stkID--] != cur) {
      parent[stk[stkID]] = cur;
      inStk[stk[stkID]] = false;
    }
  }
  return low;
}