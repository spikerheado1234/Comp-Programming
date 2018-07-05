#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int queryNumbers;
  cin >> queryNumbers;
  int counter = 1;
  for (int i = 0; i < queryNumbers; i++) {
    int arr[3];
    cin >> arr[0];
    cin >> arr[1];
    cin >> arr[2];
    sort(arr, arr + 3); 
    cout << "CASE " << counter << " " << arr[1];
    cout << endl;
    counter++;
  }
  return 0;
}
