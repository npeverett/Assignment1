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
  string info;
  string dnaInput;
  int numNucleotides;
  string nucleotideCount;
  string relProbALL;
  string relProbBigramALL;
  string genDNA;
  int numA;
  int numT;
  int numC;
  int numG;
  float relProbA;
  float relProbT;
  float relProbG;
  float relProbC;
  float relProbAA;
  float relProbAT;
  float relProbAC;
  float relProbAG;
  float relProbTA;
  float relProbTT;
  float relProbTC;
  float relProbTG;
  float relProbCA;
  float relProbCT;
  float relProbCC;
  float relProbCG;
  float relProbGA;
  float relProbGT;
  float relProbGC;
  float relProbGG;
  int lineSum;
  int numLines;
  float lineMean;
  float variance;
  float standardDeviation;
  dna();
  ~dna();
  string getFileContent(string filename);
  string myStudentInfo();
  void printRandomString();
  string printSumStats();
  string getNucleotideCount();
  string getNucleotideRelProb();
  string  getBigramRelProb();
  int getLineLength();
  float getLineMean(string filename);
  float getLineVariance(string filename);
  float getLineStandardDeviation();
private:

};

#endif
