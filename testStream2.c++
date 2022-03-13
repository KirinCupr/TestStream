#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TestData{
  string name;
  int age;
  int phoneNumber;
};

int main(int argc, char const *argv[]) {
  string nameFile = "data.data";
  TestData temp;
  cout << "Enter name: "; getline(cin, temp.name);
  cout << "Enter age: "; cin >> temp.age;
  cout << "Enter phone number: "; cin >> temp.phoneNumber;

  ofstream TOFILE(nameFile, ios::app);
  if (!TOFILE.is_open()) cout << "Error!\n ";

  TOFILE << temp.name << '\n' << temp.age << '\n' << temp.phoneNumber << "\n\n";
  TOFILE.close();

  cout << "Writing to file succeses.\n";

  ifstream FROMFILE(nameFile);
  if (!FROMFILE.is_open()) cout << "Error!\n ";
  FROMFILE.seekg(0, ios::beg);
  while (FROMFILE.eof())
  {
    getline (FROMFILE, temp.name);
    FROMFILE >> temp.age;
    FROMFILE >> temp.phoneNumber;
  }
  //FROMFILE >> temp.name >> temp.age >> temp.phoneNumber;
  cout << temp.name << '\n' << temp.age << '\n' << temp.phoneNumber;
  FROMFILE.close();
  return 0;
}
