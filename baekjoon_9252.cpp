#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void	char_to_str(string &dest, char *src)
{
	while (*src)
	{
		dest.push_back(*src);
		src++;
	}
}

string	find_lcs(vector< vector<int> > &dp, string first)
{
	string	res;
	int	row;
	int	col;
	int	temp;

	row = dp.size() - 1;
	col = dp[0].size() - 1;
	while (row > 0)
	{
		temp = col;
		while (row > 0 && dp[row][col] == dp[row - 1][col])
			row--;
		if (row == 0)
			break ;
		while (col > 0 && dp[row][col] == dp[row][col - 1])
			col--;
		if (col == 0)
		{
			row--;
			col = temp;
			continue ;
		}
		res.push_back(first[row - 1]);
		row--;
		col--;
	}
	reverse(res.begin(), res.end());
	return (res);
}

string	lcs(string first, string sec, int &max_len)
{
	int			row = first.size() + 1;
	int			col = sec.size() + 1;
	vector< vector<int> >	dp = vector< vector<int> >(row, vector<int>(col, 0));

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (first[i - 1] == sec[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
		}
	}
	max_len = dp[row - 1][col - 1];
	return (find_lcs(dp, first));
}

int	main(int argc, char **argv)
{
	string	first;
	string	sec;
	string	res;
	int	max_len;

	cin >> first >> sec;
	res = lcs(first, sec, max_len);
	cout << max_len << "\n" << res << "\n";
	return (0);
}
