#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* N = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	} 

	int* db = new int[n];
	db[0] = N[0];
	int ret;
	ret = N[0];

	for (int i = 1; i < n; ++i)
	{
		db[i] = max(db[i - 1] + N[i], N[i]);
		ret = max(db[i], ret);
	}

	cout << ret;


}