//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    void merge(int low, int mid, int high, vector<int>& arr) {
        int i = low, j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= high) {
            if (arr[i] > arr[j]) {
                temp.push_back(arr[j]);
                j++;
            } else {
                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void findCount(int low, int mid, int high, vector<int>& arr, int& count) {
        int i = low, j = mid + 1;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                i++;
            } else {
                count += (mid - i + 1);
                j++;
            }
        }
    }

    void mergeSort(int low, int high, vector<int>& arr, int& count) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        mergeSort(low, mid, arr, count);
        mergeSort(mid + 1, high, arr, count);
        findCount(low, mid, high, arr, count);
        merge(low, mid, high, arr);
    }

  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        mergeSort(0, n - 1, arr, count);
        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends