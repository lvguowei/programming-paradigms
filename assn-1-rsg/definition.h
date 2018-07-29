#ifndef __definition__
#define __definition__

#include "production.h"
#include <vector>
using namespace std;

class Definition {

public:
  Definition() {}

  Definition(ifstream &infile);

  const string &getNonterminal() const { return nonterminal; }

  const Production &getRandomProduction() const;

private:
  string nonterminal;
  vector<Production> possibleExpansions;
};

#endif // ! __definition__
