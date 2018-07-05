#include <iostream>
#include <queue>
#include <array>

using namespace std;
int rows, columns;

class Node {
  public:
    int x;
    int y;
    int value;
    bool isVisited;

    Node(int x, int y, int value, bool isVisited) {
      this->x = x;
      this->y = y;
      this->value = value;
      this->isVisited = isVisited;
    }

    Node() {
      this->x = 0;
      this->y = 0;
      this->value = 0;
      this->isVisited = false;
    }
};

void possiblepath(int startingX, int startingY, int finishingX, int finishingY, Node grid[rows][columns]) {
  if (grid[startingX][startingY].value == grid[finishingX][finishingY].value) {
    queue<Node> bfsQueue;
    bfsQueue.push(grid[startingX][startingY]);
    grid[startingX][startingY].isVisited = true;
    while(!bfsQueue.empty()) {
      if (grid[startingX][startingY].value == 0) {
        Node currentNode = bfsQueue.front();
        bfsQueue.pop();
        int currX = currentNode.x;
        int currY = currentNode.y;
        if (grid[currX+1][currY].value == 0 && grid[currX + 1][currY].isVisited == false) {
          if (((currX + 1) == finishingX) && (currY == finishingY)) {
            cout << "binary" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX+1][currY]);
        }
        if (grid[currX][currY + 1].value == 0 && grid[currX][currY + 1].isVisited == false) {
          if (((currX) == finishingX) && (currY + 1 == finishingY)) {
            cout << "binary" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX][currY + 1]);
        }
        if (grid[currX][currY - 1].value == 0 && grid[currX][currY - 1].isVisited == false) {
          if (((currX) == finishingX) && (currY - 1 == finishingY)) {
            cout << "binary" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX][currY - 1]);
        }
        if (grid[currX - 1][currY].value == 0 && grid[currX - 1][currY].isVisited == false) {
          if (((currX - 1) == finishingX) && (currY == finishingY)) {
            cout << "binary" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX - 1][currY]);
        }
      } else {
        Node currentNode = bfsQueue.front();
        bfsQueue.pop();
        int currX = currentNode.x;
        int currY = currentNode.y;
        if (grid[currX+1][currY].value == 1 && grid[currX + 1][currY].isVisited == false) {
          if (((currX + 1) == finishingX) && (currY == finishingY)) {
            cout << "decimal" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX+1][currY]);
        }
        if (grid[currX][currY + 1].value == 1 && grid[currX][currY + 1].isVisited == false) {
          if (((currX) == finishingX) && (currY + 1 == finishingY)) {
            cout << "decimal" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX][currY + 1]);
        }
        if (grid[currX][currY - 1].value == 1 && grid[currX][currY - 1].isVisited == false) {
          if (((currX) == finishingX) && (currY - 1 == finishingY)) {
            cout << "decimal" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX][currY - 1]);
        }
        if (grid[currX - 1][currY].value == 1 && grid[currX - 1][currY].isVisited == false) {
          if (((currX - 1) == finishingX) && (currY == finishingY)) {
            cout << "decimal" << endl;
            return void();
          } 
          bfsQueue.push(grid[currX - 1][currY]);
        }
      }
    }
  } else {
    cout << "neither" << endl;
  }
  cout << "neither" << endl;
}

int main() {

  // Parsing the input grid
  scanf("%d %d", &rows, &columns);
  Node *grid[rows][columns];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      int value;
      cin >> value;
      grid[i][j] = new Node(i, j, value, false);
    }
  } 

  int queries;
  scanf("%d", &queries);

  for (int i = 0; i < queries; i++) {
    int startingX;
    int startingY;
    int finishingX;
    int finishingY;
    scanf("%d %d %d %d", &startingX, &startingY, &finishingX, &finishingY);
    possiblepath(startingX, startingY, finishingX, finishingY, grid);
  }
  return 0;
}

