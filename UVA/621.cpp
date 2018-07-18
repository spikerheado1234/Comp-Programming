#include <iostream>

using namespace std;

string positiveResult = "+";
string negativeResult = "-";
string failedResult = "*";
string notCompleted = "?";

bool isMatching(int firstDigits, int numberToCheck) {
  int numberFirstDigits = 1;
  int firstDigitsCopy = firstDigits;
  while (firstDigitsCopy > 10) {
    numberFirstDigits++;
    firstDigitsCopy = firstDigitsCopy / 10;
  }
  int numberToCheckCopy = numberToCheck;
  int frontNumber = 1;
  for (int i = 0; i < numberFirstDigits; i++) {
    frontNumber = frontNumber * 10;
  }
  while (numberToCheckCopy >= frontNumber) {
    numberToCheckCopy = numberToCheckCopy / 10;
  }
  return firstDigits == numberToCheckCopy;
}


int main() {
  int numberQueries;
  cin >> numberQueries;
  cout << "Number of queries is: " << numberQueries;
  for (int i = 0; i < numberQueries; i++) {
    int currentQuery;
    cin >> currentQuery;
    if ((currentQuery == 1) || (currentQuery == 4) || (currentQuery == 78)) {
      cout << positiveResult << endl;
    } else if (currentQuery%100 == 35) { // Possible negative result.
      if (currentQuery == 135 || currentQuery == 435 || currentQuery == 7835) {
        cout << negativeResult << endl;
      } else {
        cout << positiveResult << endl;
      }
    } else if ((currentQuery % 10 == 4) && isMatching(9, currentQuery)) { // Possible experiment failed.
      if (currentQuery == 914 || currentQuery == 944 || currentQuery == 9784) {
        cout << failedResult << endl;
      } else {
        cout << positiveResult << endl;
      }
    } else if (isMatching(190, currentQuery)) { // Possible experiment not completed.
      if (currentQuery == 1901 || currentQuery == 1904 || currentQuery == 19078) {
        cout << notCompleted << endl;
      } else {
        cout << positiveResult << endl;
      }
    } else {
      cout << positiveResult << endl;
    }
  }
}
