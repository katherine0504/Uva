#include <cstdio>
#include <cstdlib>

#define MAX 25

using namespace std;

int n, t, sum, maxsum, cnt, outcnt, tmp[MAX], ans[MAX], in[MAX];

void init();
void find(int p, int s);

int main() {
  int i;
  while(scanf("%d", &n) != EOF) {
    scanf("%d", &t);
    init();

    for (i = 0; i < t; i++) {
      scanf("%d", &in[i]);
    }

    find(0,0);

    for (i = 0; i < outcnt; i++) {
      printf("%d ", ans[i]);
    }
    printf("sum:%d\n", maxsum);
  }
  return 0;
}

void init() {
  int i;
  sum = 0;
  maxsum = 0;
  cnt = 0;
  for (i = 0; i < MAX; i++) {
    tmp[i] = 0;
    ans[i] = 0;
    in[i] = 0;
  }
  
  return;
}

void find(int p, int s) {
  int i;
  if (s > maxsum) {    
    maxsum = s;
    outcnt = cnt;
    for (i = 0; i < cnt; i++) {
      ans[i] = tmp[i];
    }
  }
  
  for (i = p; i < t; i++) {
    if (s + in[i] <= n) {
      s = s + in[i];
      tmp[cnt++] = in[i];
      find(i+1, s);
      s = s - in[i];
      cnt--;
    }
  }
  return; 
}
