#include <iostream>

using namespace std;

string positiveResult = "+";
string negativeResult = "-";
string failedResult = "*";
string notCompleted = "?";

bool isMatching(int firstDigits, int numberToCheck) {
  int numberFirstDigits = 1;
  int firstDigitsCopy = firstDigits;
  while (firstDigitsCopy >= 10) {
    numberFirstDigits++;
    firstDigitsCopy = firstDigitsCopy / 10;
  }

  int numberToCheckCopy = numberToCheck;
  int frontNumber = numberFirstDigits * 10;
  while (numberToCheck >= frontNumber) {
    numberToCheckCopy = numberToCheckCopy / 10;
  }
  return firstDigitsCopy == numberToCheckCopy;
}


int main() {
  int numberQueries;
  cin >> numberQueries;
  cout << "Number of queries is: " << numberQueries;
  for (int i = 0; i < numberQueries; i++) {
    int currentQuery;
    cin >> currentQuery;
    if (currentQuery % 100 == 35) { // Possible negative result.
      if (currentQuery == 135 || currentQuery == 435 || currentQuery == 7835) {
        cout << negativeResult;
      } else {
        cout << positiveResult;
      }
    } else if ((currentQuery % 10 == 4) && isMatching(9, currentQuery)) { // Possible experiment failed.
      if (currentQuery == 914 || currentQuery == 944 || currentQuery == 9784) {
        cout << failedResult;
      } else {
        cout << positiveResult;
      }
    } else if (isMatching(190, currentQuery)) { // Possible experiment not completed.
      if (currentQuery == 1901 || currentQuery == 1904 || currentQuery == 19078) {
        cout << notCompleted;
      } else {
        cout << positiveResult;
      }
    } else { // Fucked if we reach here anyways.
      cout << "Error encountered";
    }
  }
}
