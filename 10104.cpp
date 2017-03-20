#include <cstdio>
#include <cstdlib>

using namespace std;

int gcd(int A, int B, int &X, int &Y);

int main() {
  int A, B, X, Y, D;

  while (scanf("%d %d", &A, &B) != EOF) {
    D = gcd(A, B, X, Y);
    printf("%d %d %d\n", X, Y, D);
  }
  return 0;
}

int gcd(int A, int B, int &X, int &Y) {
  if (A == 0) {
    X = 0;
    Y = 1;
    return B;
  }
  else if (B == 0) {
    X = 1;
    Y = 0;
    return A;
  }
  else if (A >= B) {
    int x, y;
    int d = gcd(A+B*(-A/B),B, x, y);
    X = x;
    Y = y+(-A/B)*x;
    return d;
  }
  else {
    int x, y;
    int d = gcd(A, B+A*(-B/A), x, y);
    Y = y;
    X = x - (B/A)*y;
    return d;
  }
}
