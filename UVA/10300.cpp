#include <iostream>

using namespace std;

int main() {
  int numberQueries;
  cin >> numberQueries;
  for (int i = 0; i < numberQueries; i++) {
    int farmers;
    cin >> farmers;
    int germanBudget;
    for (int j = 0; j < farmers; j++) {
      int sizeFarm;
      int numberAnimals;
      int friendliness;
      cin >> sizeFarm;
      cin >> numberAnimals;
      cin >> friendliness;
      germanBudget += sizeFarm * friendliness;
    }
    cout << germanBudget;
  }
}
