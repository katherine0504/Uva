#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>

#define MAX 110

using namespace std;

vector <int> edge[MAX];
int num, ans, a, b, dfs_clock;
int dfn[MAX], low[MAX];
char in[500], tmp[500];
bool isFirst;
char *ptr, token[] = " ";

void init();
void dfs(int cur, int parent);

int main() {
  int i;
  while(scanf("%d", &num) != EOF) {
    if (num == 0) {
      break;
    }

    init();

    while (1) {
      isFirst = true;
      fgets(in, sizeof(in), stdin);
      
      if (in[0] == '0') {
        break;
      }
      for (ptr = strtok(in, token); ptr; ptr = strtok(NULL, token)) {
        if (isFirst) {
          strcpy(tmp, ptr);
          a = atoi(tmp);
          isFirst = false;
        } else {
          strcpy(tmp, ptr);
          b = atoi(tmp);
          edge[a].push_back(b);
          edge[b].push_back(a);
        }
      }
    }
    dfs(1,-1);
    printf("%d\n", ans);
  }
  return 0;
}

void init() {
  int i;

  dfs_clock = 0;
  ans = 0;
  isFirst = true;

  for (i = 0; i <=num; ++i) {
    edge[i].clear();
    dfn[i] = 0;
    low[i] = 0;
  }
}

void dfs(int cur, int parent) {
  int i, nxt, len, child = 0;
  bool isCritical = false;

  low[cur] = ++dfs_clock;
  dfn[cur] = low[cur];
  
  len = edge[cur].size();

  for (i = 0; i <len ; ++i) {
    nxt = edge[cur][i];
    if(!dfn[nxt]) {
      child++;
      dfs(nxt, cur);
      
      if(low[nxt] < low[cur]) {
        low[cur] = low[nxt];
      }

      if(low[nxt] >= dfn[cur]) {
        isCritical = true;
      }
    } else if (nxt != parent) {
      if (dfn[nxt] < low[cur]) {
        low[cur] = dfn[nxt];
      }
    }
  }

  if ((child >= 2 || parent != -1) && isCritical) {
    ans++;
  }
  return;
}
