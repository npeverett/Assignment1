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

//Method to display user choice menu
string dna::userMenu()
{
  stringstream strStream;
  strStream << "A) Get Summary Statistics of DNA File"
            << "B) Generate 1000 Strings"
            << "C) Exit";
  string menu = strStream.str();
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
      case '\r':        //checking if char is new line
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
  numNucleotides = 0;
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
  strStream << "A: " << relProbA << "\n"
            << "T: " << relProbT << "\n"
            << "C: " << relProbC << "\n"
            << "G: " << relProbG;
  relProbALL = strStream.str();
  return relProbALL;

}


//Method to get relative probability of nucleotide bigrams
string dna::getBigramRelProb()
{
  string bigram = "";
  stringstream strStream;
  for(char& nucleotide : dnaInput)
  {
    if (nucleotide == '\n' || nucleotide == '\r'){
      continue;
    }
    if (bigram.length() < 2){
      bigram += nucleotide;
    }
    if (bigram == "AA"){
      relProbAA++;
    }
    if (bigram == "AT"){
      relProbAT++;
    }
    if (bigram == "AC"){
      relProbAC++;
    }
    if (bigram == "AG"){
      relProbAG++;
    }
    if (bigram == "TA"){
      relProbTA++;
    }
    if (bigram == "TT"){
      relProbTT++;
    }
    if (bigram == "TC"){
      relProbTC++;
    }
    if (bigram == "TG"){
      relProbTG++;
    }
    if (bigram == "CA"){
      relProbCA++;
    }
    if (bigram == "CT"){
      relProbCT++;
    }
    if (bigram == "CC"){
      relProbCC++;
    }
    if (bigram == "CG"){
      relProbCG++;
    }
    if (bigram == "GA"){
      relProbGA++;
    }
    if (bigram == "GT"){
      relProbGT++;
    }
    if (bigram == "GC"){
      relProbGC++;
    }
    if (bigram == "GG"){
      relProbGG++;
    }
    if (bigram.length() == 2){
      bigram = "";
    }
  }
  relProbAA = (relProbAA / (numNucleotides / 2));       //Divide amount of bigram over total number of nucleotides
  relProbAT = (relProbAT / (numNucleotides / 2));
  relProbAC = (relProbAC / (numNucleotides / 2));
  relProbAG = (relProbAG / (numNucleotides / 2));
  relProbTA = (relProbTA / (numNucleotides / 2));
  relProbTT = (relProbTT / (numNucleotides / 2));
  relProbTC = (relProbTC / (numNucleotides / 2));
  relProbTG = (relProbTG / (numNucleotides / 2));
  relProbCA = (relProbCA / (numNucleotides / 2));
  relProbCT = (relProbCT / (numNucleotides / 2));
  relProbCC = (relProbCC / (numNucleotides / 2));
  relProbCG = (relProbCG / (numNucleotides / 2));
  relProbGA = (relProbGA / (numNucleotides / 2));
  relProbGT = (relProbGT / (numNucleotides / 2));
  relProbGC = (relProbGC / (numNucleotides / 2));
  relProbGG = (relProbGG / (numNucleotides / 2));
  strStream << "AA: " << relProbAA << "\n"        //adding all values to string for ease of reading
            << "AT: " << relProbAT << "\n"
            << "AC: " << relProbAC << "\n"
            << "AG: " << relProbAG << "\n"
            << "TA: " << relProbTA << "\n"
            << "TT: " << relProbTT << "\n"
            << "TC: " << relProbTC << "\n"
            << "TG: " << relProbTG << "\n"
            << "CA: " << relProbCA << "\n"
            << "CT: " << relProbCT << "\n"
            << "CC: " << relProbCC << "\n"
            << "CG: " << relProbCG << "\n"
            << "GA: " << relProbGA << "\n"
            << "GT: " << relProbGT << "\n"
            << "GC: " << relProbGC << "\n"
            << "GG: " << relProbGG;
  string relProbBigramALL = strStream.str();
  return relProbBigramALL;
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
float dna::getLineMean(string filename)
{
  fin.open(filename);
  string line;
  numLines = 0;
  while (getline(fin,line)){
    ++numLines;
  }
  lineMean = lineSum / numLines;     //dividing total characters by number of lines
  fin.close();                      // Closing/Resetting File
  fin.clear();
  fin.seekg(0, fin.beg);
  return lineMean;

}



//Method to calculate variance of line lengths
float dna::getLineVariance(string filename)
{
  fin.open(filename);
  string line = "";
  int varSumValues = 0;
  int lineLength = 0;
  while (getline(fin, line))
  {
    for (char ch : line)
    {
      if (ch == '\n' || ch == '\r'){
        varSumValues += pow((lineLength - lineMean),2);  // (xi-x)^2
        lineLength = 0; //reset to zero for new line length
      }
    lineLength++;
    }
  }
  variance = varSumValues / (numLines);
  return variance;
}

float dna::getLineStandardDeviation()
{
  float standardDeviation = sqrt(variance); //SD is square root of variance
  return standardDeviation;
}
