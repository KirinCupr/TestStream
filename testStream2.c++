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
  string nameFile = "data.txt";
  TestData temp;
  cout << "Enter name: "; getline(cin, temp.name);
  cout << "Enter age: "; cin >> temp.age;
  cout << "Enter phone number: "; cin >> temp.phoneNumber;

  ofstream TOFILE(nameFile);
  if (!TOFILE.is_open()) cout << "Error!\n ";

  TOFILE << temp.name << "###" << temp.age << "###" << temp.phoneNumber;
  TOFILE.close();

  cout << "Writing to file succeses.\n";

  ifstream FROMFILE(nameFile);
  if (!FROMFILE.is_open()) cout << "Error!\n ";
  char ch;
  while (FROMFILE.get(ch) && ch != '#')
  {
      FROMFILE >> temp.name;
      break;
  }
  while (FROMFILE.get(ch) && ch != '#')
  {
      FROMFILE >> temp.age;
      break;
  }
  while (FROMFILE.get(ch) && ch != '#')
  {
      FROMFILE >> temp.phoneNumber;
      break;
  }

  //FROMFILE >> temp.name >> temp.age >> temp.phoneNumber;
  cout << temp.name << '\n' << temp.age << '\n' << temp.phoneNumber;

  return 0;
}
