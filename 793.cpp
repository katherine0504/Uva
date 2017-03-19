#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

#define MAX 10000

using namespace std;

int case_num, len, in1, in2, succ, f;
char op;
string input;

int arr[MAX];

void init();
void Union(int a, int b);
int Find(int a);

int main() {
  int i, j;
  scanf("%d\n", &case_num);

  for (i = 0; i < case_num; i++) {
    scanf("%d\n", &len);
    succ = 0;
    f = 0;
    init();
    while(1) {
      if(!getline(cin, input) || input.empty() )
        break;
      sscanf(input.c_str(), "%c %d %d", &op, &in1, &in2);
      
      if (op == 'c') {
        /* connect */
        Union(in1, in2);
      }
      else if (op == 'q') {
        /* query */
        if (Find(in1) == Find(in2))
          succ++;
        else
          f++;
      }
    }
    if (i != 0 )
      printf("\n");
    printf("%d,%d\n", succ, f);
  }
  return 0;
}

void init() {
  int i;
  for (i = 1; i < MAX; i++) {
    arr[i] = i;
  }
  return;
}

void Union(int a, int b) {
  int A = Find(a);
  int B = Find(b);

  arr[A] = B;
  return;
}

int Find (int a) {
  if ( a == arr[a] )
    return a;
  return arr[a] = Find(arr[a]);
}
