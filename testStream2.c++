#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string nameFile = "data.txt";

  string temp;
  cout << "Enter info: "; cin >> temp;

  ofstream out(nameFile, ios::app);
  if (!out.is_open()) cout << "Error: bad output\n";
  out.write((char *) &temp, sizeof temp);
  out.close();

  ifstream in (nameFile);
  if (!in.is_open()) cout << "Error: bad input file\n";
  string inputTemp;
  while (!in.eof()){
      in.read((char *) &inputTemp, sizeof inputTemp);
  }
  in.close();

  cout << inputTemp;
  return 0;
}
