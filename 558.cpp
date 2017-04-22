#include <cstdio>
#include <cstdlib>

#define INF 1000000000
#define MAX 5000

int c, n, m, dis[MAX];

struct Edge{
  int x;
  int y;
  int len;
} edge[MAX];

void init();
bool BellmanFord();

int main() {
  int i, j, x, y, tmp;
  scanf("%d", &c);
  for (i = 0; i < c; i++) {
    scanf("%d %d", &n, &m);
    init();
    for (j = 0; j < m; ++j) {
      scanf("%d %d %d", &edge[j].x, &edge[j].y, &edge[j].len);
    }

    if (BellmanFord()) {
      printf("possible\n");
    } else {
      printf("not possible\n");
    }

    for (j = 0; j < m; ++j) {
      edge[j].x = 0;
      edge[j].y = 0;
      edge[j].len = 0;
    }
  }
  return 0;
}

void init() {
  int i, j;
  dis[0] = 0;
  for(i = 1; i <= n; ++i) {
    dis[i] = INF;
  }
  return;
}

bool BellmanFord() {
  int i, j;

  for (i = 0; i < n-1; ++i) {
    for (j = 0; j < m; ++j) {
      if (dis[edge[j].x] + edge[j].len < dis[edge[j].y]) {
        dis[edge[j].y] = dis[edge[j].x] + edge[j].len;
      }
    }
  }
  for (i = 0; i < m; ++i) {
    if (dis[edge[i].x] + edge[i].len < dis[edge[i].y]) {
      return true;
    }
  }
  return false;
}
