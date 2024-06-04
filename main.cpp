#include <iostream>
#include <cstring>

using namespace std;

int correctInput();

int main() {
  // Create board and fill diagonals with 0's and blanks with spaces
  char board[21][21];
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (i == j) {
	board[i][j] = '0';
      }
      else {
	board[i][j] = ' ';
      }
    } 
  }
  // Create char array for vertex labels and fill with the char '-'
  char letters[21];
  for (int i = 0; i < 20; i++) {
    letters[i] = '-';
  }
  int vertexNums = 0;
  
  bool looping = true;
  while (looping == true) {
    int option = correctInput();
    // Add vertex
    if (option == 1) {
      vertexNums++;
      cout << "Enter the label for the vertex." << endl;
      char vertexLabel;
      cin >> vertexLabel;
      cin.get();
      int index = 0;
      while (index < 21) {
	if (letters[index] == '-') {
	  letters[index] = vertexLabel;
	  index = 1000;
	}
	index++;
      }
    }
    // Add edge
    else if (option == 2) {
      cout << "Please enter the vertex label of the origin." << endl;
      char vertexOrigin;
      cin >> vertexOrigin;
      cin.get();
      
      cout << "Please enter the vertex label of the destination." << endl;
      char vertexDestination;
      cin >> vertexDestination;
      cin.get();
      
      cout << "What is the weight of the edge?" << endl;
      char edgeWeight;
      cin >> edgeWeight;
      cin.get();

      int indexOrigin;
      int indexDestination;

      // Find the indices of the origin and destination
      for (int i = 0; i < vertexNums; i++) {
	if (vertexOrigin == letters[i]) {
	  indexOrigin = i;
	}
	if (vertexDestination == letters[i]) {
	  indexDestination = i;
	}
      }
      // Add to the appriopriate location in the board
      board[indexOrigin][indexDestination] = edgeWeight;      
    }
    // Remove vertex
    else if (option == 3) {
      // DOESN'T FULLY WORK!!
      cout << "Please enter the vertex label." << endl;
      char vertexLabel;
      cin >> vertexLabel;
      cin.get();

      int vertexIndex;
      // Find index for the deleted vertex
      for (int i = 0; i < vertexNums; i++) {
	if (vertexLabel == letters[i]) {
	  vertexLabel = i;
	}
      }

      // Shift the labels
      for (int i = vertexLabel; i < vertexNums; i++) {
	letters[i] = letters[i+1];
      }
      vertexNums--;

      // Fix the board (DOESN'T WORK)
      for (int i = 0; i < vertexNums; i++) {
	for (int j = 0; j < vertexNums; j++) {
	  if (i == vertexIndex || j == vertexIndex) {
	    board[i][j] == ' ';
	  }
	}
      }
      board[vertexIndex][vertexIndex] = 0;
    }
    // Remove edge
    else if (option == 4) {
      cout << "Please enter the vertex label of the origin." << endl;
      char vertexOrigin;
      cin >> vertexOrigin;
      cin.get();
      
      cout << "Please enter the vertex label of the destination." << endl;
      char vertexDestination;
      cin >> vertexDestination;
      cin.get();

      int indexOrigin;
      int indexDestination;

      // Find indices for origin and destination
      for (int i = 0; i < vertexNums; i++) {
	if (vertexOrigin == letters[i]) {
	  indexOrigin = i;
	}
	if (vertexDestination == letters[i]) {
	  indexDestination = i;
	}
      }
      // Remove edge
      board[indexOrigin][indexDestination] = ' ';
    }
    // Print
    else if (option == 5) {
      cout << endl;
      // Print labels horizontally
      for (int i = 0; i < vertexNums; i++) {
	if (i == 0) {
	  cout << "    ";
	}
	cout << letters[i] << "   ";
      }
      cout << endl;
      // Print labels vertically as well as the board
      for (int i = 0; i < vertexNums; i++) {
	cout << letters[i] << "   ";
	for (int j = 0; j < vertexNums; j++) {
	  if (board[i][j] != ' ') {
	    cout << board[i][j] << "   ";
	  }
	  else {
	    cout << "    ";
	  }
	}
	cout << endl << endl;
      }
      cout << endl << endl;
    }
    // Quit the program
    else if (option == 6) {
      looping = false;
    }
  }
}

int correctInput() {
  bool leaveLoop = false;
  cout << "Enter one of the following options: ADDVER, ADDEDGE, REMOVEVER, REMOVEEDGE, PRINT, or QUIT (uppercase)" << endl;
  while (leaveLoop == false) {
    char input[15];
    cin.get(input, 15);
    cin.ignore(15, '\n');
    if (strcmp(input, "ADDVER") == 0) {
      return 1;
    }
    else if (strcmp(input, "ADDEDGE") == 0) {
      return 2;
    }
    else if (strcmp(input, "REMOVEVER") == 0) {
      return 3;
    }
    else if (strcmp(input, "REMOVEEDGE") == 0) {
      return 4;
    }
    else if (strcmp(input, "PRINT") == 0) {
      return 5;
    }
    else if (strcmp(input, "QUIT") == 0) {
      return 6;
    }
    else {
      cout << "Please enter a valid option." << endl;
    }
  }
  return -1;
}
