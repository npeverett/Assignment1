#include <iostream>
#include <fstream>
#include "dnaHead.h"

using namespace std;


int main(){
  dna d;
  cout << d.myStudentInfo() << endl;
  cout << "" << endl;
  cout << "Enter file name: ";
  string answer;
  cin >> answer;
  cout << "" << endl;
  d.getFileContent(answer);
  cout << d.getNucleotideCount() << endl;
  cout << " " << endl;
  cout << d.getNucleotideRelProb() << endl;
  cout << "Sum of line lengths: " << d.getLineLength() << endl;
  cout << "Average length of line: " << d.getLineMean(answer) << endl;
  //cout << d.getNucleotideRelProb() << endl;
  //cout << d.getLineLength(answer) << endl;
  //  cout << d.getLineMean(answer) << endl;
  return 0;
}
