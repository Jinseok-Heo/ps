#include <stdio.h>
#include <memory.h>

int find_parent(int x, int* data) {
	if (x == data[x]) {
		return x;
	} else {
		int y = find_parent(data[x], data);
		data[x] = y;
		return y;
	}
}

char is_same_parent(int x, int y, int* data) {
	int x_parent = find_parent(x, data);
	int y_parent = find_parent(y, data);
	if (x_parent == y_parent) { return '1'; }
	else {  return '0'; }
}

void union_sets(int x, int y, int* data, int* depth_of_tree) {
	int x_parent = find_parent(x, data);
	int y_parent = find_parent(y, data);
	if (x_parent != y_parent) {
		if (depth_of_tree[x_parent] < depth_of_tree[y_parent]) {
			data[x_parent] = y_parent;
			depth_of_tree[y_parent] = depth_of_tree[y_parent] < depth_of_tree[x_parent] + 1 ? depth_of_tree[y_parent] : depth_of_tree[x_parent] + 1;
		} else {
			data[y_parent] = x_parent;
			depth_of_tree[x_parent] = depth_of_tree[x_parent] < depth_of_tree[y_parent] + 1 ? depth_of_tree[x_parent] : depth_of_tree[y_parent] + 1;
		}
	}
}

int main() {
	const int MAX_SIZE = 1000000 + 1;
	int n, m;
	scanf("%d %d", &n, &m);
	int data[MAX_SIZE];
	int depth_of_tree[MAX_SIZE];
	
	for (int i = 0; i <= n; i++) {
		data[i] = i;
	}
	memset(depth_of_tree, 1, sizeof(int));

	for (int i = 0; i < m; i++) {
		int order, x, y;
		scanf("%d %d %d", &order, &x, &y);
		if (order == 0) {
			union_sets(x, y, data, depth_of_tree);
		} else if (order == 1) {
			if (is_same_parent(x, y, data) == '1') {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
