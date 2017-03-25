#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

double left, right, mid, ans, ep = 0.00000001;
int p, q, r, s, t, u;

double func (double x) {
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x*x) + u;
}

int main () {
  while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF ) {
    left = 0;
    right = 1;
    mid = (left+right)/2;
    ans = func(mid);  
    while (1) {
      if (fabs(ans - 0) < ep) {
        printf("%.4f\n", mid);
        break;
      }
      else if ( left == right) {
        printf("No solution\n");
        break;
      }
      else if (ans > 0) {
        left = mid;
        mid = (left+right)/2;
        ans = func(mid);
      }
      else {
        right = mid;
        mid = (left+right)/2;
        ans = func(mid);
      }
    }
  }
  return 0;
}
