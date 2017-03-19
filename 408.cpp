#include <cstdio>
#include <cstdlib>

using namespace std;

int in1, in2;
int gcd(int a, int b);

int main() {
  while (scanf("%d %d", &in1, &in2) != EOF) {
    if (gcd(in1, in2) == 1) {
      printf("%10d%10d    Good Choice\n\n", in1, in2);
    }
    else {
      printf("%10d%10d    Bad Choice\n\n", in1, in2);
    }
  }
  return 0;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b%a, a);
}
