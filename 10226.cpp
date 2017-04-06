#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int num, cnt;
double ans;
string in;

int main () {
  int i;
  scanf("%d", &num);
  getchar();
  getline(cin, in);

  for (i = 0; i < num; i++) {
    map<string, int> M;
    cnt = 0;
    
    if (i != 0) {
      printf("\n");
    }
    
    while(getline(cin, in) && in != "") {
      cnt++;
      if (!M[in]) {
        M[in] = 1;
      } else {
        M[in]++;
      }
    }

    map<string, int>::iterator it;

    for (it = M.begin(); it != M.end(); it++) {
      cout << it->first;
      printf(" %.4f\n", ((double)it->second)/((double)cnt)*100);
    }
  }
  return 0;
}
