#include <iostream>

using namespace std;

int main() {
  int numberQueries;
  cin >> numberQueries;
  for (int i = 0; i < numberQueries; i++) {
    int farmers;
    cin >> farmers;
    long germanBudget = 0;
    for (int j = 0; j < farmers; j++) {
      long sizeFarm;
      long numberAnimals;
      long friendliness;
      cin >> sizeFarm;
      cin >> numberAnimals;
      cin >> friendliness;
      germanBudget += sizeFarm * friendliness;
    }
    cout << germanBudget << endl;
  }
}
