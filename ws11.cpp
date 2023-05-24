#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // Include the <stdexcept> header for exception handling
using namespace std;

typedef vector<int> Records;

class RecordsManager {
 private:
  fstream _file;
  string _filename;

 public:
  RecordsManager(string filename) : _filename(filename) {}

  void read(Records& records) {
    try {
      _file.open(_filename, ios::in);
      if (_file.is_open()) {
        string line;
        while (getline(_file, line)) {
          records.push_back(stoi(line));
        }
        _file.close();
      } else {
        throw runtime_error("Failed to open the file."); // Throw an exception if the file cannot be opened
      }
    } catch (const invalid_argument& e) {
      _file.close();
      throw runtime_error("Wrong argument when reading the file: " + string(e.what())); // Throw an exception with an error message for invalid argument
    } catch (const out_of_range& e) {
      _file.close();
      throw runtime_error("Out of range when reading the file: " + string(e.what())); // Throw an exception with an error message for out of range
    } catch (...) {
      _file.close();
      throw; // Re-throw any other exceptions not caught explicitly
    }
  }
};

int main() {
  try {
    RecordsManager recordM("test_clean.txt");
    // RecordsManager recordM("test_corrupt1.txt");
    // RecordsManager recordM("test_corrupt2.txt");
    Records myRecords;
    recordM.read(myRecords);

    int sum = 0;
    for (int i = 0; i < myRecords.size(); i++) {
      sum += myRecords[i];
    }
    cout << sum << endl;
  } catch (const exception& e) {
    cout << "Error: " << e.what() << endl; // Handle the exception and print the error message
  }

  return 0;
}
