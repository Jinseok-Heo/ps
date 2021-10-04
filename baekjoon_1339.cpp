#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define pq priority_queue<string, vector<string>, cmp>

using namespace std;

struct cmp
{
	bool operator()(string a, string b)
	{
		return a.size() > b.size();
	}
};

string	solution(pq &strs)
{
	int	n;

	n = strs.size();
	while (!strs.empty())
	{
		
	}
}

int	main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int		n;
	pq		strs;
	string	temp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		strs.push(temp);
	}

	
}