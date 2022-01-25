#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {

    deque<int> q;
    deque<int> maxValues;

    for (int i = 0; i < n; i++) {

        if (maxValues.empty() || arr[i] >= maxValues.front()) {
            maxValues.push_front(arr[i]);
        }

        q.push_back(arr[i]);

        if (q.size() == k) {

            cout << maxValues.front() << " ";

            while (!maxValues.empty() || q.front() <= maxValues.front()) {
                maxValues.pop_front();
            }

            q.pop_front();
        }
    }

    cout << endl;
}

int dequeeHackerrank() {

    int t = 1;
    // cin >> t;
    while (t > 0) {
        /*
        const int n = 5;
        const int k = 2;
        int arr[n] = { 3, 4, 6, 3, 4 };

        const int n = 7;
        const int k = 4;
        int arr[n] = { 3, 4, 5, 8, 1, 4, 10 };

        const int n = 8;
        const int k = 5;
        int arr[n] = { 3, 4, 5, 8, 1, 4, 10, 6 }; // 8 8 10 10

        const int n = 12;
        const int k = 4;
        int arr[n] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; // 1 1 1 1 1 1 1 1 
        */

        const int n = 8;
        const int k = 3;
        int arr[n] = { 2, 3, 4, 4, 4, 1, 1, 2 }; // 4 4 4 4 4 2
        // int n, k;
        // cin >> n >> k;
        // int i;
        // for (i = 0; i < n; i++)
        //    cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}

