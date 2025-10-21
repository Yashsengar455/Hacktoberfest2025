#include <vector>
#include <iostream>
using namespace std;

/*
LeetCode 852: Peak Index in a Mountain Array

Problem:
A mountain array is an array where elements strictly increase to a peak and then strictly decrease. 
We need to find the index of the peak element.

Example:
Input: arr = [0, 2, 3, 4, 5, 3, 1]
Output: 4
Explanation: The peak element is 5 at index 4.

Approach:
We can solve this efficiently using Binary Search. 
The idea is to check the middle element:
1. If the middle element is greater than the next element, the peak is at mid or to its left.
2. If the middle element is less than the next element, the peak is to the right of mid.

This works because of the mountain property: strictly increasing then strictly decreasing.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Start from index 1 and go to index n-2
        // because the first and last elements cannot be peaks
        int left = 1;
        int right = arr.size() - 2;

        while (left < right) {
            int mid = left + (right - left) / 2; // middle index

            // Compare mid element with next element
            if (arr[mid] > arr[mid + 1]) {
                // We are on the descending slope
                // So the peak is at mid or somewhere to the left
                right = mid;
            } else {
                // We are on the ascending slope
                // So the peak is somewhere to the right
                left = mid + 1;
            }
        }

        // When left == right, we found the peak
        return left;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {0, 2, 3, 4, 5, 3, 1};
    int peakIndex = sol.peakIndexInMountainArray(arr);
    cout << "Peak index: " << peakIndex << endl; // Output: 4
    cout << "Peak element: " << arr[peakIndex] << endl; // Output: 5
    return 0;
}
