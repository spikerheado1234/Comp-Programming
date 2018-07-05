#include <iostream>
#include <algorithm>
using namespace std;

int recurse(int);

int main() {
  int numQueries;
  cin >> numQueries;

  for (int i = 0; i < numQueries; i++) {
    int number;
    cin >> number;
    cout << recurse(number);
    cout << endl;
  }
}


int recurse(int number) {
  if (number < 10) {
    return number;
  } else {
    int currSum = 0;
    while (number != 0) {
      currSum += number % 10;
      number -= number % 10;
      number = number / 10;
    }
    return recurse(currSum);
  }
}
