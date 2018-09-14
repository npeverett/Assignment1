#include <iostream>
#include <fstream>
#include <sstream>
#include "dnaHead.h"

using namespace std;

int main(int argc, char **argv)
{
  if (argv[1] == NULL){              //Checks against if a filename isn't given
    cout << "Please Enter A File Name To Run Program." << endl;
  }
  else{

  dna d;

  //Prints contents to console
  d.getFileContent(argv[1]);
  cout << " " << endl;
  cout << d.myStudentInfo() << endl;
  cout << " " << endl;
  cout << "Total Number Of: " << endl;
  cout << d.getNucleotideCount() << endl;
  cout << " " << endl;
  cout << "Relative Probability Of: " << endl;
  cout << d.getNucleotideRelProb() << endl;
  cout << " " << endl;
  cout << "Relative Bigram Probability Of: " << endl;
  cout << d.getBigramRelProb() << endl;
  cout << " " << endl;
  cout << "Sum: " << d.getLineLength() << endl;
  cout << "Mean: " << d.getLineMean(argv[1]) << endl;
  cout << "Variance: " << d.getLineVariance(argv[1]) << endl;
  cout << "Standard Deviation: " << d.getLineStandardDeviation() << endl;
  cout << " " << endl;
  d.printRandomString();
  d.printSumStats();
  cout << " " << endl;
  }

  //Asking to process another file
  cout << "Would you like to process another file? Y/N" << endl;
  while(true){
  char answer;
  cin >> answer;
  answer = toupper(answer);
  if (answer == 'Y'){
    cout << "Enter new file name: " << endl;
    string newFileName;
    cin >> newFileName;
    dna d2;
    d2.getFileContent(newFileName);
    cout << " " << endl;
    cout << d2.myStudentInfo() << endl;
    cout << " " << endl;
    cout << "Total Number Of: " << endl;
    cout << d2.getNucleotideCount() << endl;
    cout << " " << endl;
    cout << "Relative Probability Of: " << endl;
    cout << d2.getNucleotideRelProb() << endl;
    cout << " " << endl;
    cout << "Relative Bigram Probability Of: " << endl;
    cout << d2.getBigramRelProb() << endl;
    cout << " " << endl;
    cout << "Sum: " << d2.getLineLength() << endl;
    cout << "Mean: " << d2.getLineMean(newFileName) << endl;
    cout << "Variance: " << d2.getLineVariance(newFileName) << endl;
    cout << "Standard Deviation: " << d2.getLineStandardDeviation() << endl;
    cout << " " << endl;
    d2.printRandomString();
    d2.printSumStats();
    cout << " " << endl;
    break;
  }
  else if (answer == 'N'){
    exit(0);
  }
  else{
    cout << "Please only enter Y or N respectively" << endl;
    continue;
  }
  }

  return 0;
}
