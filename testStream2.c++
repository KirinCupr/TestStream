#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TestData{
  string name;
  string age;
  string phoneNumber;
};

int main(int argc, char const *argv[]) {
  string nameFile = "data.txt";

  TestData temp;
  cout << "Enter info: ";
  getline(cin, temp.name);
  getline(cin, temp.age);
  getline(cin, temp.phoneNumber);

  ofstream out(nameFile, ios::app);
  if (!out.is_open()) cout << "Error: bad output\n";
  out.write((char *) &temp, sizeof temp);
  out.close();

  ifstream in (nameFile);
  if (!in.is_open()) cout << "Error: bad input file\n";
  TestData inputTemp;
  in.seekg(0, ios::beg);
  while (!in.eof()){
      in.read((char *) &inputTemp, sizeof inputTemp);
  }
  in.close();

  cout << inputTemp.name << '\n';
  cout << inputTemp.age << '\n';
  cout << inputTemp.phoneNumber << '\n';

  return 0;
}
