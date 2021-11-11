#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 987654321

using namespace std;

typedef pair<int, int> int_pair;

void	print_maze(vector<string> &maze) {
	for (int i = 0; i < maze.size(); i++)
		cout << maze[i] << "\n";
}

void	init_maze(vector<string> &maze, vector< vector<int> > &weights) {
	int n, m;
	cin >> n >> m;
	maze.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> maze[i];
	}
	weights.resize(maze.size());
	for (int i = 0; i < weights.size(); i++) {
		weights[i].resize(maze[0].size(), INF);
	}
	weights[0][0] = 0;
}

int	solution(vector<string> &maze, vector< vector<int> > &weights) {
	queue<int_pair> q;
	int	m = maze.size();
	int	n = maze[0].size();
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int	y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int	new_x = x + dx[i];
			int	new_y = y + dy[i];
			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
				if (weights[new_y][new_x] <= weights[y][x] + maze[new_y][new_x] - '0') continue ;
				weights[new_y][new_x] = weights[y][x] + maze[new_y][new_x] - '0';
				q.push(make_pair(new_x, new_y));
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << weights[i][j] << " ";
		cout << "\n";
	}
	return (weights[m - 1][n - 1]);
}

int	main(void) {
	int						n;
	int						m;
	vector<string>			maze;
	vector< vector<int> >	weights;

	init_maze(maze, weights);
	cout << solution(maze, weights) << "\n";
}
