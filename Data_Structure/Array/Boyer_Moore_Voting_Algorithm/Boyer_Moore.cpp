// C++ implementation for the above approach
#include <bits/stdc++.h>
using namespace std;
// Function to find majority element
int findMajority(int arr[], int n)
{
	int i, candidate = -1, votes = 0;
	// Finding majority candidate
	for (i = 0; i < n; i++) {
		if (votes == 0) {
			candidate = arr[i];
			votes = 1;
		}
		else if (arr[i] == candidate) votes += 1;
		else votes -= 1;
	}
	int cnt = 0;
	// Checking if majority candidate occurs more than n/2
	// times
	for (i = 0; i < n; i++) {
		if (arr[i] == candidate)
			cnt++;
	}

	if (cnt > n / 2)
		return candidate;
	return -1;
}
int main()
{
	int arr[] = { 1, 1, 2, 3, 4, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int majority = findMajority(arr, n);
	cout << " The majority element is : " << majority;
	return 0;
}
