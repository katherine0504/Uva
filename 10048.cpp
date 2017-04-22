#include <cstdio>
#include <cstdlib>

#define INF 1000000000

int dis[110][110];
int C, S, Q, caseCnt, mx;

int main() {
  int i, j, k, x, y, num;
  caseCnt = 1;

  while (scanf("%d %d %d", &C, &S, &Q)) {
    if (C == 0 & S == 0 & Q == 0) {
      break;
    }
    
    for (i = 1; i <= C; ++i) {
      for (j = 1; j <= C; ++j) {
        dis[i][j] = INF;
        dis[j][i] = INF;
      }
      dis[i][i] = 0;
    }

    for (i = 0; i < S; ++i) {
      scanf("%d %d %d", &x, &y, &num);
      dis[x][y] = num;
      dis[y][x] = num;
    }

    for (i = 1; i <= C; ++i) {
      for (j = 1; j <= C; ++j) {
        for (k = 1; k <= C; ++k) {
          if (dis[j][i] > dis[i][k]) {
            mx = dis[j][i];
          } else {
            mx = dis[i][k];
          }

          if (dis[j][k] > mx) {
            dis[j][k] = mx;
          }
        }
      }
    }
    if (caseCnt != 1) {
      printf("\n");
    }
    printf("Case #%d\n", caseCnt++);

    for (i = 0; i < Q; ++i) {
      scanf("%d %d", &x, &y);
      if (dis[x][y] == INF) {
        printf("no path\n");
      } else {
        printf("%d\n", dis[x][y]);
      }
    }
  }
  return 0;
}
