#include <iostream>
#include <fstream>
#include <math.h>
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
  info = name + "\n" + id + "\n" + assn;
  return info;
}

void dna::printRandomString()
{
  string generatedDNA = "";
  float a,b;    //random numbers
  float c,d;    //random standard variabes
  int count = 0;
  const string charList = "ATGCatgc";
  string newString = "";
  genDNA = "";
  srand(time(0));
  a = ((float)rand() / (RAND_MAX));             //set initial values for a,b,c,d (WILL BE CHANGED LATER);
  b = ((float)rand() / (RAND_MAX));

  c = sqrt(-2*log(a)) * cos(2* M_PI * b);
  d = (standardDeviation * c) + lineMean;

  while(count < 1001)
  {
    for (int i = 0; i < d; i++){
      newString += charList[rand() % charList.size()];
    }
    newString += '\n';
    a = ((float)rand() / (RAND_MAX));           //recalculate a,b,c,d for random line length
    b = ((float)rand() / (RAND_MAX));
    c = sqrt(-2*log(a)) * cos(2* M_PI * b);
    d = (standardDeviation * c) + lineMean;
    genDNA += newString;
    count++;
    newString = "";                             //reset string for a new line
  }
}

//Method to Read through DNA file
string dna::getFileContent(string filename)
{
  stringstream strStream;                       //use stringstream for ease of reading in output
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
  nucleotideCount = "";
  for (char& nucleotide : dnaInput )
  {
    nucleotide = toupper(nucleotide);
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
        cout << "Character other than ATCG found. This program only analyzes DNA nucleotides. Please enter a file accordingly" << endl;
        exit(0);        //cannot complete computations on invalid chars
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
  for (char& nucleotide : dnaInput)
  {
    nucleotide = toupper(nucleotide);
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
    nucleotide = toupper(nucleotide);
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
  relProbBigramALL = strStream.str();
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

//Method to calculate Standard Deviation of line length
float dna::getLineStandardDeviation()
{
  standardDeviation = sqrt(variance); //SD is square root of variance
  return standardDeviation;
}

string dna::printSumStats()
{
  fout.open("nathanaelEverett.txt", ios::trunc);
  fout << " " << endl;
  fout << info << endl;
  fout << " " << endl;
  fout << "Total Number Of: " << endl;
  fout << nucleotideCount << endl;
  fout << " " << endl;
  fout << "Relative Probability Of: " << endl;
  fout << relProbALL << endl;
  fout << " " << endl;
  fout << "Relative Bigram Probability Of: " << endl;
  fout << relProbBigramALL << endl;
  fout << " " << endl;
  fout << "Sum: " << lineSum << endl;
  fout << "Mean: " << lineMean << endl;
  fout << "Variance: " << variance << endl;
  fout << "Standard Deviation: " << standardDeviation << endl;
  fout << " " << endl;
  fout << genDNA << endl;
  return ("Summary Statistics Additionally Printed to File.");
}
