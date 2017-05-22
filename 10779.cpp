#include <cstdio>
#include <cstring>
#include <queue>

#define INF 100000000
#define MAX 105

using namespace std;

int cap[MAX][MAX], flow[MAX][MAX], bottleneck[MAX], pre[MAX];
int cnt, N, M, K, T, casecnt = 1;
queue <int> Q;

int BFS(int N, int S, int T);

int main () {
	int i, j, k, ki;

	scanf("%d", &cnt);
	
	for(k = 0; k < cnt; ++k) {
		scanf("%d %d", &N, &M);
		T = N+M+1;
		
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		
		for (i = 1; i <= N; ++i){
			scanf("%d", &K);

			for (j = 1; j <= K; ++j){
				scanf("%d", &ki);
				cap[i][N+ki]++;
			}
		}
		
		for(i = 2; i <= N; ++i){
			for(j = N+1; j <= N+M; ++j){
				if(cap[i][j]){
					cap[i][j]--;
				}	else {
					cap[j][i] = 1;
				}
			}
		}
		
		for(i = N+1; i <= N+M; ++i) {
			cap[i][T] = 1;
		}
	
		printf("Case #%d: %d\n", casecnt++, BFS(T, 1, T));
	}
}

int BFS(int N, int S, int T){
	int i, nxt, cur, result = 0;
	while (1) {
		for(i = 0; i <= N+1; ++i) {
			bottleneck[i] = 0;
		}

		bottleneck[S] = INF;
		
		while (!Q.empty()) {
			Q.pop();
		}

		Q.push(S);
		
		while (!Q.empty() && !bottleneck[T]) {
			cur = Q.front();
			Q.pop();
			
			for (nxt = 1; nxt <= N; ++nxt) {
				if (!bottleneck[nxt] && cap[cur][nxt] > flow[cur][nxt]) {
					Q.push(nxt);
					pre[nxt] = cur;

					if (bottleneck[cur] < (cap[cur][nxt] - flow[cur][nxt])) {
						bottleneck[nxt] = bottleneck[cur];
					} else {
						bottleneck[nxt] = cap[cur][nxt] - flow[cur][nxt];
					}
				}
			}
		}

		if (!bottleneck[T]) {
			break;
		}
		
		for (cur = T; cur != S; cur = pre[cur]) {
			flow[pre[cur]][cur] = flow[pre[cur]][cur] + bottleneck[T];
			flow[cur][pre[cur]] = flow[cur][pre[cur]] - bottleneck[T];
		}

		result = result + bottleneck[T];
	}
	return result;
}