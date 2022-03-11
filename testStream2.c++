#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string nameFile = "data.txt";

  string temp;
  cout << "Enter info: "; cin >> temp;

  ofstream out(nameFile, ios_base::binary);
  out.write((char *) &temp, sizeof temp);
  out.seekp(1, ios_base::cur);
  out.close();

  ifstream in (nameFile, ios_base::binary);
  if (!in.is_open()) cout << "Error: bad input file";
  string inputTemp;
  in.read((char *) &temp, sizeof temp);
  in.close();

  cout << inputTemp;
  return 0;
}
