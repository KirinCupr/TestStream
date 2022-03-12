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
  cout << '\n' << out.tellp() << '\n';
  out.write((char *) &temp, sizeof temp);
  cout << '\n' << out.tellp() << '\n';
  out.close();

  cout << "\nCheck\n\n";

  ifstream in ;
  in.open (nameFile);
  cout << '\n' << in.tellg() << '\n';
  //in.seekg(0, ios::beg);
  if (!in.is_open()) cout << "Error: bad input file\n";
  TestData inputTemp;
  getline (in, inputTemp.name);
  /*while (!in.eof()){
      in.read((char *) &inputTemp, sizeof inputTemp);
  }*/
  in.close();

  cout << inputTemp.name << '\n';
  cout << inputTemp.age << '\n';
  cout << inputTemp.phoneNumber << '\n';

  return 0;
}
