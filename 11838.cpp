#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 2000000

using namespace std;

vector <int> edge[MAX];
vector <int> tar;
int num, len, a, b, dfs_clock, cnt, way;
int dfn[MAX], low[MAX];

void init();
void Tarjan(int cur);

int main() {
  int i;
  while(scanf("%d %d", &num, &len) != EOF) {
    if (num == 0 && len == 0) {
      break;
    }

    init();

    for (i = 0; i < len; ++i) {
      scanf("%d %d %d", &a, &b, &way);
      if (way == 1) {
        edge[a].push_back(b);
      } else if (way == 2) {
        edge[a].push_back(b);
        edge[b].push_back(a);
      }
    }
    
    for(i = 1; i <= num; ++i) {
      if(!dfn[i] && cnt < 2) {
        Tarjan(i);
      }
    }

    if(cnt == 1) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
  return 0;
}

void init() {
  int i;

  dfs_clock = 0;
  cnt = 0;

  tar.clear();

  for (i = 0; i <= MAX; ++i) {
    edge[i].clear();
    dfn[i] = 0;
    low[i] = 0;
  }
}

void Tarjan(int cur) {
  int i, nxt, len, child = 0;
  bool isCritical = false;

  low[cur] = ++dfs_clock;
  dfn[cur] = low[cur];

  tar.push_back(cur);
  
  len = edge[cur].size();

  for (i = 0; i < len ; ++i) {
    nxt = edge[cur][i];
    if(!dfn[nxt]) {
      Tarjan(nxt);
      
      if(low[nxt] < low[cur]) {
        low[cur] = low[nxt];
      }
    } else if (find(tar.begin(), tar.end(), nxt) != tar.end()) {
      if (dfn[nxt] < low[cur]) {
        low[cur] = dfn[nxt];
      }
    }
  }

  if (dfn[cur] == low[cur]) {
    cnt++;
    nxt = tar.back();
    tar.pop_back();

    while(cur != nxt) {
      nxt = tar.back();
      tar.pop_back();
    }
  }
  return;
}
