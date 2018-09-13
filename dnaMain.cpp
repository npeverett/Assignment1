#include <iostream>
#include <fstream>
#include "dnaHead.h"

using namespace std;

int main(int argc, char **argv)
{
  if (argv[1] == NULL){              //Checks against if a filename isn't given
    cout << "Please Enter A File Name To Run Program." << endl;
  }
  else{
  dna d;
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
  }
  return 0;
}
