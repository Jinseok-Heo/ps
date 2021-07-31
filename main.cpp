#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <functional>
#include <unordered_map>
#include <random>
#include <ctime>

#define p pair<int, int>
#define ll long long
#define INF 9876543211

using namespace std;

void inputData(int &numberOfPoint, vector<vector<p>>& container) {
    cin >> numberOfPoint;

    container.resize(numberOfPoint + 1);

    for (int i = 0; i < numberOfPoint; i++) {
        int first, second, dist;
        cin >> first;

        while (true) {
            cin >> second;
            if (second == -1) {
                break;
            } else {
                cin >> dist;
                container[first].push_back(pair(second, dist));
            }
        }
    }
}

void dfs(const vector<vector<p>>& container, vector<bool>& isVisited, int& diameter, int& farthestNode, int currentNode, int currentDistance) {
    if (isVisited[currentNode]) return;

    isVisited[currentNode] = true;

    if (diameter < currentDistance) {
        diameter = currentDistance;
        farthestNode = currentNode;
    }

    for (int i = 0; i < container[currentNode].size(); i++) {
        dfs(container, isVisited, diameter, farthestNode, container[currentNode][i].first, currentDistance + container[currentNode][i].second);
    }
}

int solution(vector<vector<p>>& container) {
    int diameter = 0, farthestNode = 0;
    vector<bool> isVisited(container.size(), false);
    dfs(container, isVisited, diameter, farthestNode, 1, 0);
    isVisited.clear();
    isVisited.resize(container.size(), false);
    diameter = 0;
    dfs(container, isVisited, diameter, farthestNode, farthestNode, 0);
    return diameter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfPoint;
    vector<vector<p>> container;

    inputData(numberOfPoint, container);
    cout << solution(container) << '\n';

    return 0;
}