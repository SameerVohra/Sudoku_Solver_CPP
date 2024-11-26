#include<bits/stdc++.h>
using namespace std;

void printSudoku(vector<vector<char>>& arr){
  cout << endl << " Current Sudoku " <<endl;
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
}

bool isValidSudoku(vector<vector<char>>& arr){
  for(int i=0; i<9; i++){
    unordered_set<char> rMap;
    for(int j=0; j<9; j++){
      if(arr[i][j]!='.' && rMap.find(arr[i][j])!=rMap.end()) return false;
      rMap.insert(arr[i][j]);
    }
  }

  for(int i=0; i<9; i++){
    unordered_set<char> cMap;
    for(int j=0; j<9; j++){
      if(arr[j][i]!='.' && cMap.find(arr[j][i])!=cMap.end()) return false;
      cMap.insert(arr[j][i]);
    }
  }

  vector<unordered_set<char>> mat(9);
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      int loc = (i/3)*3 + j/3;
      if(arr[i][j]!='.' && mat[loc].find(arr[i][j])!=mat[loc].end()) return false;
      mat[loc].insert(arr[i][j]);
    }
  }

  return true;
}

bool isValidMove(vector<vector<char>>& arr, int r, int c, char ch){
  for(int i=0; i<9; i++){
    if(arr[i][c]==ch) return false;
    if(arr[r][i]==ch) return false;
    if(arr[3*(r/3)+i/3][3*(c/3)+i%3] == ch) return false;
  }

  return true;
}

bool solveSudoku(vector<vector<char>>& arr){
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(arr[i][j]=='.'){
        for(char c='1'; c<='9'; c++){
          if(isValidMove(arr, i, j, c)){
            arr[i][j] = c;
            if(solveSudoku(arr)) return true;
            else arr[i][j]='.';
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main(){
    vector<vector<char>> arr(9, vector<char>(9, '.'));
    int r, c;

  cout << "+--------------------------------------------+" << endl;
  cout << "|  Enter r=-1 and c=-1 to stop giving input  |" << endl;
  cout << "+--------------------------------------------+" << endl;

  while(r!=-1 || c!=-1){

    printSudoku(arr);

    cout << "Enter the row and column number(0-based indexing)" << endl;
    cout << "Enter Row: ";
    cin >> r;
    cout << "Enter Column: ";
    cin >> c;

    if(r<0 || c<0 || c>9 || r>9) break;

    cout << "Enter Number you want to insert on " << r << " " << c << endl;
    string num;
    cin >> num;

    if(num>="1" && num<="9") arr[r][c] = num[0];
    else cout << "Number should be less than 10" << endl;
  }

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  if(isValidSudoku(arr)){
    solveSudoku(arr);
    cout << endl << endl << "SOLVED SUDOKU" << endl << endl;
    printSudoku(arr);
  }
  else cout << "Sudoku is not valid" << endl;
}
