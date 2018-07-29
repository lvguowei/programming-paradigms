#ifndef __production__
#define __production__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Production {

public:
  typedef vector<string>::iterator iterator;
  typedef vector<string>::const_iterator const_iterator;

public:
  Production() {}

  Production(ifstream &infile);

  Production(const vector<string> &words) : phrases(words) {}

  iterator begin() { return phrases.begin(); }
  const_iterator begin() const { return phrases.begin(); }
  iterator end() { return phrases.end(); }
  const_iterator end() const { return phrases.end(); }

private:
  vector<string> phrases;
};

#endif
