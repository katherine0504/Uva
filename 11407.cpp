#include <cstdio>
#include <cstdlib>
#include <cmath>

#define MAX 10010

using namespace std;

int ans[MAX], num, times, in;

int main () {
  int i, j;
  for (i = 0; i < MAX; i++) {
    ans[i] = 10000;
  }
  ans[0] = 0;  
  ans[1] = 1;

  for (i = 2; i <= 10000; i++) {
    for (j = sqrt(i); i-(j*j) >= 0 ; j--) {
      times = ans[i-(j*j)] + 1;
      if (times < ans[i]) {
        ans[i] = times;
      }
    }
  }

  scanf("%d", &num);

  for (i = 0; i < num; i++) {
    scanf("%d", &in);
    printf("%d\n", ans[in]);
  }

  return 0;
}
