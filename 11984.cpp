#include <cstdio>
#include <cstdlib>

using namespace std;

int len;
double in1, in2, out;

int main() {
  int i;
  scanf("%d", & len);
  
  for (i = 0; i < len; i++) {
    scanf("%lf %lf", &in1, &in2);
    printf("Case %d: %.2lf\n", i+1, (in1+(in2*5/9)));  
  }
  return 0;
}
