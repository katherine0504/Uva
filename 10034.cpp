#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define MAX 110

using namespace std;

struct point {
  double x;
  double y;
} P[MAX];

struct edge {
  int x;
  int y;
  double len;
} E[MAX*MAX];

int casenum, edgecnt, cnt, n;
int disjoint[MAX];
double ans;

void init();
bool Union(edge A);
int Find(int x);
bool cmp(edge A, edge B);

int main () {
  int i, j, k;

  scanf("%d", &casenum);
  
  for (i = 0; i < casenum; ++i) {
    scanf("%d", &n);
    for (j = 0; j < n; ++j) {
      scanf("%lf %lf", &P[j].x, &P[j].y);
    }

    init();

    for (j = 0; j < n; ++j) {
      for (k = j + 1; k < n; ++k) {
        E[edgecnt].x = j;
        E[edgecnt].y = k;
        E[edgecnt++].len = sqrt(pow(P[j].x - P[k].x, 2) + pow(P[j].y - P[k].y, 2));
      }
    }

    sort(E, E+edgecnt, cmp);

    for (j = 0; cnt != n-1; ++j) {
      if(Union(E[j])) {
        ++cnt;
      }
    }

    if(i > 0) {
      printf("\n");
    }
    printf("%.2f\n", ans);
  }
  return 0;
}

void init() {
  int i;
  
  ans = 0;
  edgecnt = 0;
  cnt = 0;

  for (i = 0; i < n; ++i) {
    disjoint[i] = i;
  }
  return;
}

int Find(int x) {
  if(x == disjoint[x]) {
    return x;
  } else {
    return disjoint[x] = Find(disjoint[x]);
  }
}

bool Union(edge A) {
  int x = Find(A.x);
  int y = Find(A.y);

  if (x != y) {
    disjoint[x] = y;
    ans = ans + A.len;
    return true;
  } else {
    return false;
  }
}

bool cmp (edge A, edge B) {
  return A.len < B.len;
}
