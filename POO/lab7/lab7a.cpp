
#include <iostream>
using namespace std;

template <class T> void bubbleSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        {
            int val = rand() % 1000;
            a[i] = val;
        }

	bubbleSort<int>(a, n);

	cout << " Sorted array : ";
	for (int i = n-1; i >= 0; --i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}
