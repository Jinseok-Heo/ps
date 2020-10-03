#include<iostream>

#define H_MASS 1
#define C_MASS 12
#define O_MASS 16

using namespace std;

int quantity(char c)//return quantity of 'H', 'C' and 'O'
{
	if (c == 'H')
		return H_MASS;
	if (c == 'O')
		return O_MASS;
	if (c == 'C')
		return C_MASS;
	return 0;
}

int main() 
{
	int idx, temp;
	idx = 0;//idx means level of small brakets
	temp = 0;
	int arr[100]{ 0, };//temporary storage which can store sum of quantity from '(' to ')'
	char str[105];

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++) 
	{
		//if str[i] is 'H', 'C' or 'O' add quantity to arr[idx]
		if (str[i] > 'A' && str[i] < 'Z')
		{
			temp = quantity(str[i]);
			arr[idx] += temp;
		}
		//if str[i] is '(' add 1 to idx which means quantities should be added to next level
		else if (str[i] == '(')
			arr[++idx] = 0;
		//if str[i] is ')' add sum from '(' to ')' to arr[idx - 1] and make quantities be stored to previous level
		else if (str[i] == ')' && idx > 0)
		{
			temp = arr[idx];
			arr[idx - 1] += temp;
			--idx;
		}
		//if str[i] is number add temp * (num - 1) to arr[idx] (we already added temp at previous sequence)
		else if (str[i] >= '2' && str[i] <= '9')
			arr[idx] += temp * (str[i] - '0' - 1);
	}
	cout << arr[0];
	return 0;
}