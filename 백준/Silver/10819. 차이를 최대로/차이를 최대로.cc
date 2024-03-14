#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int n;
	int max = 0;
    cin.tie(0);
	cin >> n;

	vector<int> num(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	do {
		int sum = 0;

		for (int i = 0; i < n - 1; i++)
		{
			sum += abs(num[i] - num[i + 1]);
		}
		if (sum > max) {
			max = sum;
		}

	} while (next_permutation(num.begin(), num.end()));

	cout << max;

}