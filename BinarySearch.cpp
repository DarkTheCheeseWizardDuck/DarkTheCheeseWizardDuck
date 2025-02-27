#include <iostream>
#include <iomanip>
using namespace std;

//prob 0
void prob_0() {
    cout << "prob 0" << endl;
    cout << "enter array's size"<< endl;
    int n, x;
    cin >> n;
    int a[n];
    cout << "enter array"<< endl;
    for (int i=0; i<=n-1; i++){
        cin >> a[i];
    }
    cout << "what to find?" << endl;
    cin >> x;

    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == x){
            cout << mid << endl;
            found = true;
            break;
        }
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1; 
    }
    if (found!=true) cout << -1 << endl;
}


//prob 1

double FindMedian(int arr1[], int m, int arr2[], int n) {
    int left = 0, right = m;
    int total = m + n;
    int half = (total + 1) / 2;

    while (left <= right) {
        int i = (left + right) / 2;
        int j = half - i;

        int left1 = (i > 0) ? arr1[i - 1] : -1000000000;
        int right1 = (i < m) ? arr1[i] : 1000000000;
        int left2 = (j > 0) ? arr2[j - 1] : -1000000000;
        int right2 = (j < n) ? arr2[j] : 1000000000;

        if (left1 <= right2 && left2 <= right1) {
            return (total % 2 == 1) ? max(left1, left2) : (max(left1, left2) + min(right1, right2)) / 2.0;
        }
        if (left1 > right2) right = i - 1;
        else left = i + 1;
    }
    return 0; 
}

void prob_1() {
    cout << "prob 1" << endl;
    int m, n;
    cout << "enter first array's size: ";
    cin >> m;
    cout << "enter second array's size: ";
    cin >> n;

    int* arr1 = new int[m];
    int* arr2 = new int[n];

    cout << "enter array 1: ";
    for (int i = 0; i < m; i++) cin >> arr1[i];

    cout << "enter array 2: ";
    for (int i = 0; i < n; i++) cin >> arr2[i];

    if (m > n) {
        swap(m, n);
        swap(arr1, arr2);
    }

    cout << FindMedian(arr1, m, arr2, n) << endl;

    delete[] arr1;
    delete[] arr2;
}

//prob 2
int findFirst(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    int first = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            first = mid;   
            right = mid - 1;  
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first;
}

int findLast(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    int last = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            last = mid; 
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

void prob_2(){
    cout << "prob 2" << endl;
    cout << "enter array's size"<< endl;
    int n, x;
    cin >> n;
    int a[n];
    cout << "enter array"<< endl;
    for (int i=0; i<=n-1; i++){
        cin >> a[i];
    }
    cout << "what to find?" << endl;
    cin >> x;
    int first = findFirst(a, n, x);
    int last = findLast(a, n, x);
    cout << "[" << first << ", " << last << "]" << endl;
}

//prob 3

int search(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

     
        if (nums[left] <= nums[mid]) { 
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        } else { 
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
void prob_3() {
    cout << "prob 3" << endl;
    cout << "enter array's size"<< endl;
    int n, x;
    cin >> n;
    int a[n];
    cout << "enter array"<< endl;
    for (int i=0; i<=n-1; i++){
        cin >> a[i];
    }
    cout << "what to find?" << endl;
    cin >> x;

    cout << search(a, n, x) << endl;
}

//prob 4
void prob_4() {
    cout << "prob 4" << endl;
    cout << "enter array's size"<< endl;
    int n;
    cin >> n;
    int a[n];
    cout << "enter array"<< endl;
    for (int i=0; i<=n-1; i++){
        cin >> a[i];
    }

    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] >= a[mid+1] && a[mid] >= a[mid-1]){
            cout << mid;
            break;
        }
        else if (a[mid] < a[mid+1])
            left = mid + 1;
        else if (a[mid] > a[mid-1])
            right = mid - 1; 
    }
}


int main(){
    prob_0();
    prob_1();
    prob_2();
    prob_3();
    prob_4();
    return 0;
}


