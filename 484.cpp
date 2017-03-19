#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct info {
	int num;
	int cnt;
} s;

int input;
bool found;

int main() {
	vector<info> v;
	int i;

	scanf("%d", &input);
	s.num = input;
	s.cnt = 1;
	v.push_back(s);

	while (scanf("%d", &input) != EOF) {
		found = false;
		for (i = 0; i< v.size(); i++ ) {
			if (v[i].num == input) {
				v[i].cnt ++;
				found = true;
			}
		}

		if (!found) {
			s.num = input;
			s.cnt = 1;
			v.push_back(s);
		}
	}

	for (i = 0; i< v.size(); i++) {
		printf("%d %d\n", v[i].num, v[i].cnt);
	}

	return 0;
}
