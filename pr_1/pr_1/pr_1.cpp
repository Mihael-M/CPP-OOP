#include <iostream>
using namespace std;
int borders(int len)
{

}
bool binarySearchRecursive(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

       
        if (arr[mid] == target) {
            return true;
        }

        
        if (arr[mid] > target) {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }

       
        return binarySearchRecursive(arr, mid + 1, right, target);
    }

    return false;
}
bool binSearch(int arr[], int target)
{
    binarySearchRecursive(arr[],  ,  ,target);
}
int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int size =6;
    int target = 7;

    if (binarySearchRecursive(arr, 0, size - 1, target)) {
        cout << "Number " << target << " is found.";
    }
    else {
       cout << "Number " << target << " is not found.";
    }

    return 0;
}