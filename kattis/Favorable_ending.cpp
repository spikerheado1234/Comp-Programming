#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
string favorable = "favourably";

int main() {
  int testCases;
  cin >> testCases;
  for (int i = 0; i < testCases; i++) {
    cout << "Executed once" << endl;
    int numberSections;
    cin >> numberSections;
    vector<int> queries;
    unordered_map<int, int> map;
    for (int j = 0; j < numberSections; j++) {
      cout << "Value of j is: " << j << endl;
      int pageNumber;
      string ending;
      cin >> pageNumber;
      int nextSection;
      cin >> nextSection;
      cout << "A" << endl;
      if (cin.fail()) { // We have reached the ending of a section. Need to check if it is a favorable one to query later.
        cout << "B" << endl;
        cin.clear();
        cin >> ending;
        if (ending.compare(favorable) == 0) {
          queries.push_back(pageNumber);
        }
      } else { // Not the ending of a section must add everything into the hash and continue.
        cout << "B" << endl;
        int nextSectionTwo;
        int nextSectionThree;
        cin >> nextSectionTwo;
        cin >> nextSectionThree;
        unordered_map<int, int>::const_iterator one = map.find(nextSection);
        unordered_map<int, int>::const_iterator two = map.find(nextSectionTwo);
        unordered_map<int, int>::const_iterator three = map.find(nextSectionThree);
        if (one != map.end()) {
          map[nextSection] += map[nextSection];
        } else {
          map[nextSection] = 1;
        }

        cout << "C" << endl;
        if (two != map.end()) {
          map[nextSectionTwo] += map[nextSectionTwo];
        } else {
          map[nextSectionTwo] = 1;
        }

        cout << "D" << endl;
        if (three != map.end()) {
          map[nextSectionThree] += map[nextSectionThree];
        } else {
          map[nextSectionThree] = 1;
        }
      }
      int temp = numberSections - 1;
      cout << "The value of numberSections - 1 is: " << temp << endl;
      bool isTrue = (j == (numberSections - 1));
      cout << "The boolean value is: " << isTrue << endl;
      if (j == (numberSections - 1)) {
        int currentAnswer = 0;
        for (int a = 0; a < queries.size(); a++) {
          int currentQuery = queries.at(a);
          currentAnswer += map.find(currentQuery)->second;
        }
        cout << currentAnswer << endl;
      } else {
        continue;
      }
    }
  }
}
