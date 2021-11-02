#include <iostream>
#include <vector>
#include <queue>
#define PAIR pair<int, int>
#define INF 987654321

using namespace std;

struct cmp {
	bool operator()(PAIR a, PAIR b) {
		return a.second > b.second;
	}
};

void	dijkstra(int n, int s, vector< vector<PAIR> > &v, vector<int> &sol) {
	priority_queue<PAIR, vector<PAIR>, cmp>	pq;

	pq.push(make_pair(s, 0));
	while(!pq.empty()) {
		int cur_loc = pq.top().first; // Current Location
		int cur_dist = pq.top().second; // Distance from start
		pq.pop();
		if (sol[cur_loc] < cur_dist) continue ;
		for (int i = 0; i < v[cur_loc].size(); i++) {
			int	next_loc = v[cur_loc][i].first;
			int next_dist = v[cur_loc][i].second;
			if (sol[next_loc] > sol[cur_loc] + next_dist) { // Check distance to next location is larger than new one
				sol[next_loc] = sol[cur_loc] + next_dist; // If larger than new, update
				pq.push(make_pair(next_loc, sol[next_loc]));
			}
		}
	}
}

int solution(int n, int s, int e, vector< vector<PAIR> > &v) {
	vector<int>	sol(n + 1, INF);

	sol[s] = 0;
	dijkstra(n, s, v, sol);
	return sol[e];
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int						n, m, s, e;
	vector< vector<PAIR> >	v;

	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
	}
	cin >> s >> e;
	cout << solution(n, s, e, v) << endl;
}
