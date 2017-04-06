#include <iostream>
#include <cstdio>
#include <string>
#include <map>

#define MAX 20000

using namespace std;

int num, len, mx;
string in, tmp, out;

int main () {
  int i;
  map<string, int> M;

  while(cin >> num) {
    cin.get();
    getline(cin, in);
    mx = 1;
    len = in.length();
    for (i = 0; i <= len-num; i++) {
      tmp = in.substr(i, num);
      if (!M[tmp]) {
        M[tmp] = 1;
      } else {
        M[tmp]++;
        if (mx < M[tmp]) {
          mx = M[tmp];
          out = tmp;
        }
      }
    }
    cout << out << endl;
  }  
  return 0;
}
