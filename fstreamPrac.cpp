#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream outputFile(name+".txt");
  string line;
  getline(outputFile,line);
  cout << line << endl;
  return 0;
}
