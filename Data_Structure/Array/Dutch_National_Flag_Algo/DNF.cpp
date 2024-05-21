#include <bits/stdc++.h>
using namespace std;
void dutchNationalFlag(vector<int>& vec, int n) {
    int low = 0, mid = 0, high = n - 1; // 3 pointers
    while (mid <= high) {
        if (vec[mid] == 0) {
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if (vec[mid] == 1) {
            mid++;
        }
        else {
            swap(vec[mid], vec[high]);
            high--;
        }
    }
}
int main()
{
    int n = 6;
    vector<int> vec = {0, 2, 1, 2, 0, 1};
    dutchNationalFlag(vec, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}