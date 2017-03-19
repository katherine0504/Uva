#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX 1000000

using namespace std;

long long int input;
bool isPrime[MAX];

void eratosthenes();

int main () {
  int i, j;

  eratosthenes();
 
  while ((scanf("%lld", &input) != EOF) && input >= 0) {
    for (i = 0; i < MAX; i++) {
      if (isPrime[i]) {
        while ( input % i == 0 ) {
          printf("    %d\n", i);
          input = input/i;
        }

        if (input == 1) {
          break;
        }
      }
    }

    if (input != 1) {
      printf("    %lld\n", input);
    }

    printf("\n");
  }
  return 0;
}

void eratosthenes() {
  int i, j;
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for (i = 2; i <= sqrt(MAX); ++i) {
    if (isPrime[i]) {
      for (j = i*i; j < MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return;
}
