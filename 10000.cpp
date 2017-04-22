#include <cstdio>
#include <cstdlib>

#define INF 1000000000
#define MAX 10010

struct EDGE {
  int x;
  int y;
} edge[MAX];

int n, s, cnt, caseCnt, mn, now, dis[110];

int main() {
  int i, j;
  caseCnt = 1;
  while (scanf("%d", &n)) {
    if (n == 0) {
      break;
    }
    scanf("%d", &s);
    cnt = 0;
    mn = INF;

    for (i = 1; i <= n; i++) {
      dis[i] = INF;
    }
    dis[s] = 0;

    while(scanf("%d %d", &edge[cnt].x, &edge[cnt].y)) {
      if (edge[cnt].x == 0 && edge[cnt].y == 0) {
        break;
      }
      cnt++;
    }

    for (i = 0; i < n-1; ++i) {
      for (j = 0; j < cnt; ++j) {
        if (dis[edge[j].x] - 1 < dis[edge[j].y]) {
          dis[edge[j].y] = dis[edge[j].x] - 1;
        }
      }
    }
    
    now = s;
    for (i = 1; i <= n; ++i) {
      if (dis[i] < mn) {
        mn = dis[i];
        now = i;
      }
    }

    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", caseCnt++, s, -mn, now);
    
  }
  return 0;
}
