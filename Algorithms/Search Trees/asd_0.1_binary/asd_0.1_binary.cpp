#include <iostream>
using namespace std;

bool binarysearch(long long* arr, int size, int x){
    int low = 0;
    int up = size;
    while (low < up) {
        int k = (low + up) / 2;
        if (x == arr[k])
          return true;
        else if (x < arr[k])
         up = k;
        else
          low = k + 1;  
    }
    return false;
}

int lower(long long* arr, int size, int x){
    int low = 0;
    int up = size;
    while (low < up){
       int i = (low + up) / 2;
       if (x <= arr[i])
           up = i;
        else
          low = i + 1;    
    }
    return low;
}

int upper(long long* arr, int size, int x) {
    int low = 0;
    int up = size;
    while (low < up){
       int i = (low + up) / 2;
       if (x < arr[i])
          up = i;
        else
           low = i + 1;
    }
    return low;
}

int main() {
    int size;
    cin >> size;
    long long* arr = new long long[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int size_requests;
    cin >> size_requests;
    long long* requests = new long long[size_requests];
    int request;
    for (int i = 0; i < size_requests; i++) {
        cin >> request;
        requests[i] = request;
    }
    for (int i = 0; i < size_requests; i++) {
        cout << binarysearch(arr, size, requests[i]) << " " << lower(arr, size, requests[i]) << " " << upper(arr, size, requests[i]) << endl;
    }
    delete[]arr;
    delete[] requests;
    return 0;
}
