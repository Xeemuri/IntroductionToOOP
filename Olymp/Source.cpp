#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int n, S, counter = 0;
	cin >> n >> S;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	double mean = 0,mean1 = 0;
	for (int i = 0; i < n; i++)
	{
		mean1 = (S - arr[i]) / (n-1);
		if (mean1 / arr[i] >= 2|| arr[i] / mean1 >= 2) counter++;
	}
	cout << counter << endl;
	return 0;
}