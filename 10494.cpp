#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

unsigned long long int in1, in2;
char op, in[1000];
int cnt, ans[1000];
bool fnd;

int main() {
  int i;  
  while (scanf("%s %c %lld", &in, &op, &in2) != EOF ) {
    in1  = 0;
    cnt = 0;
    fnd = false;
    for (i = 0; in[i]; i++) {
      in1 = in1*10 + (in[i] - '0');
      ans[cnt] = in1/in2;
      in1 = in1 % in2;
      cnt ++;
    }

    if (op == '/') {
      for ( i = 0; i < cnt; i++) {
        if (ans[i] == 0 && !fnd) {
          continue;
        }
        else if ( i == cnt-1 && ans[i] == 0 && !fnd) {
          printf("0");
        }
        else {
          fnd = true;
          printf("%d", ans[i]);
        }
      }
      if ( !fnd)
        printf("0");
      printf("\n");
    }
    else if (op == '%') {
      printf("%lld\n", in1);
    }
  }
  return 0;
}
