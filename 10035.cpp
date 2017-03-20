#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int tmp1, tmp2, ans, carry, cnt;
long long int in1, in2;

int main() {
  int i;
  while (scanf("%lld %lld", &in1, &in2)) {
    if (in1 == 0 && in2 == 0) {
      return 0;
    }
    cnt = 0;
    carry = 0;

    while (in1 != 0 || in2 != 0) {
      tmp1 = in1 % 10 + carry;
      tmp2 = in2 % 10;
      ans = tmp1 + tmp2;
      
      if (ans >= 10) {
        cnt++;
        carry = ans/10;
      }

      else {
        carry = 0;
      }
      in1 = in1/10;
      in2 = in2/10;
    }

    if (cnt == 0) {
      printf("No carry operation.\n");
    }
    else if (cnt == 1) {
      printf("1 carry operation.\n");
    }
    else {
      printf("%d carry operations.\n", cnt);
    }
  }
  return 0;
}
