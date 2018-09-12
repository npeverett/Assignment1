#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "dnaHead.h"


using namespace std;

//Class Empty Constructor
dna::dna(){
}

//Class Destructor
dna::~dna(){
  cout<<"Destructor Invoked."<<endl;
}


//Method to display personal student information
string dna::myStudentInfo()
{
  const string name = "Name:        Nathanael Everett";
  const string id   = "ID:          2296318";
  const string assn = "Assignment:  Assignment 1";
  const string info = name + "\n" + id + "\n" + assn;
  return info;
}


//Method to Read through DNA file
string dna::getFileContent(string filename)
{
  stringstream strStream;
  fin.open(filename);
  if (fin.is_open())
  {
    strStream << fin.rdbuf();
    dnaInput = strStream.str();
  }
  else{
    cout << "Unable to open file. Please try again."  << endl;
    exit(0);
  }
  fin.close();
  return dnaInput;
}



//Method to get sum of dna nucleotide
string dna::getNucleotideCount()
{
  stringstream strStream;
  string nucleotideCount;
  for (char& nucleotide : dnaInput )
  {
    switch (nucleotide)  //using switch to check nucleotide type
    {
      case 'A':
        numA += 1;
        break;
      case 'T':
        numT += 1;
        break;
      case 'C':
        numC += 1;
        break;
      case 'G':
        numG += 1;
        break;
      case '\r':
        break;
      case '\n':
        break;
      default:
        cout << "Character other than ATCG found" << endl;
        //numA = 0;     //reset values if file has error
        //numT = 0;
        //numC = 0;
        //numG = 0;
    }
  }
  strStream << "A: " << numA << "\n"
            << "T: " << numT << "\n"
            << "C: " << numC << "\n"
            << "G: " << numG;
  nucleotideCount = strStream.str();
  return nucleotideCount;
}





//Method to get the relative probability of each nucleotide
string dna::getNucleotideRelProb()
{
  int numNucleotides = 0;
  stringstream strStream;
  string relProbALL;
  for (char& nucleotide : dnaInput)
  {
    if (nucleotide == '\n' || nucleotide == '\r'){
      continue;
    }
    numNucleotides += 1;
  }
  relProbA = (float)numA / numNucleotides;  //number of A nucleotides over total
  relProbT = (float)numT / numNucleotides;  //number of T nucleotides over total
  relProbC = (float)numC / numNucleotides;
  relProbG = (float)numG / numNucleotides;
  strStream << "Relative Probability of A: " << relProbA << "\n"
            << "Relative Probability of T: " << relProbT << "\n"
            << "Relative Probability of C: " << relProbC << "\n"
            << "Relative Probability of G: " << relProbG;
  relProbALL = strStream.str();
  return relProbALL;

}



//Method to find sum of DNA string length
int dna::getLineLength()
{
    for (char& ch : dnaInput)
    {
      if (ch == '\n' || ch == '\r'){
        continue;
      }

      lineSum++;
    }
  return lineSum;
}



//Method to find mean of DNA string length
int dna::getLineMean(string filename)
{
  fin.open(filename);
  string line;
  numLines = 0;
  while (getline(fin,line)){
    numLines ++;
  }
  meanLineLength = numLines / lineSum; //dividing total characters by number of lines
  return meanLineLength;
}



//Method to calculate variance of line lengths
/*int dna::getLineVariance(string filename)
{
  fin.open(filename);
  string line;
  int varSumValues = 0;
  while (getline(fin,line))
  {
    for (string s : line)
    {
      varSumValues += pow((s.length() - meanLineLength),2);
    }
  }
  variance = varSumValues / (numLines - 1);
  return variance;
}
*/
