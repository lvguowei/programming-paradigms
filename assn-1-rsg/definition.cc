#include "definition.h"
#include "random.h"

Definition::Definition(ifstream &infile) {
  string uselessText;
  getline(infile, uselessText, '{');
  infile >> nonterminal;
  getline(infile, uselessText); // stop character defaults to '\n'

  while (infile.peek() != '}') {
    Production possibleExpansion(infile);
    possibleExpansions.push_back(possibleExpansion);
  }

  getline(infile, uselessText, '}');
}

const Production &Definition::getRandomProduction() const {
  static RandomGenerator random;
  int randomIndex = random.getRandomInteger(0, possibleExpansions.size() - 1);
  return possibleExpansions[randomIndex];
}
