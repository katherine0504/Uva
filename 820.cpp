#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 110
#define INF 1000000000

using namespace std;

int n, s, t, c, cnt, ans;
int cap[MAX][MAX], flow[MAX][MAX], bottleneck[MAX], pre[MAX];
queue <int> Q;

void init();
int BFS(int N, int S, int T);

int main() {
  int i, in1, in2, bandwidth;

  cnt = 0;

  while(scanf("%d", &n) != EOF) {
    if (n == 0) {
      break;
    }

    init();

    scanf("%d %d %d", &s, &t, &c);
    
    for (i = 0; i < c; ++i) {
      scanf("%d %d %d", &in1, &in2, &bandwidth);
      cap[in2][in1] = cap[in2][in1] + bandwidth;
      cap[in1][in2] = cap[in2][in1];
    }

    ans = BFS(n, s, t);
    printf("Network %d\n", ++cnt);
    printf("The bandwidth is %d.\n\n", ans);
  }
  return 0;
}

void init() {
  int i;
  
  memset(pre, 0, sizeof(int)*MAX);

  for (i = 1; i <= n; ++i) {
    memset(cap[i], 0, sizeof(int)*MAX);
    memset(flow[i], 0, sizeof(int)*MAX);
  }
  return;
}

int BFS (int N, int S, int T) {
  int result = 0;
  int nxt, cur;
  while(1) {
    while(!Q.empty()) {
      Q.pop();
    }

    memset(bottleneck, 0, sizeof(int)*N+2);
    Q.push(S);
    bottleneck[S] = INF;

    while(!Q.empty() && !bottleneck[T]) {
      cur = Q.front();
      Q.pop();

      for(nxt = 1; nxt <= N; ++nxt) {
        if (!bottleneck[nxt] && cap[cur][nxt] > flow[cur][nxt]) {
          Q.push(nxt);
          pre[nxt] = cur;
          if((cap[cur][nxt] - flow[cur][nxt]) < bottleneck[cur]) {
            bottleneck[nxt] = cap[cur][nxt] - flow[cur][nxt];
          } else {
            bottleneck[nxt] = bottleneck[cur];
          }
        }
      }
    }

    if(!bottleneck[T]) {
      break;
    }

    for (cur = T; cur != S; cur = pre[cur]) {
      flow[pre[cur]][cur] = flow[pre[cur]][cur] + bottleneck[T];
      flow[cur][pre[cur]] = flow[cur][pre[cur]] - bottleneck[T];
    }

    result = result + bottleneck[T];
  }
  return result;
}
