#ifndef dnaHead
#define dnaHead
#include <iostream>
#include <fstream>

using namespace std;

//class declaration
class dna{
public:
  ifstream fin;
  ofstream fout;
  string filename;
  string dnaInput;
  int numA;
  int numT;
  int numC;
  int numG;
  float relProbA;
  float relProbT;
  float relProbG;
  float relProbC;
  int lineSum;
  int numLines;
  int meanLineLength;
  int variance;
  dna();
  ~dna();
  string getFileContent(string filename);
  string myStudentInfo();
  string getNucleotideCount();
  string getNucleotideRelProb();
  int getLineLength();
  int getLineMean(string filename);
  int getLineVariance(string filename);
private:

};

#endif
