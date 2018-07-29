/**
 * File: rsg.cc
 * ------------
 * Provides the implementation of the full RSG application, which
 * relies on the services of the built-in string, ifstream, vector,
 * and map classes as well as the custom Production and Definition
 * classes provided with the assignment.
 */

#include "definition.h"
#include "production.h"
#include <fstream>
#include <map>
using namespace std;

static void readGrammar(ifstream &infile, map<string, Definition> &grammar) {
  while (true) {
    string uselessText;
    getline(infile, uselessText, '{');
    if (infile.eof())
      return; // true? we encountered EOF before we saw a '{': no more
              // productions!
    infile.putback('{');
    Definition def(infile);
    grammar[def.getNonterminal()] = def;
  }
}

string compose(Production &production, map<string, Definition> &grammar) {

  string result = "";
  for (Production::iterator curr = production.begin(); curr != production.end();
       ++curr) {
    string phrase = *curr;
    if (phrase[0] == '<') {
      Definition def = grammar[phrase];
      Production prod = def.getRandomProduction();
      result = result + compose(prod, grammar);
    } else {
      result = result + " " + phrase;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    cerr << "You need to specify the name of a grammar file." << endl;
    cerr << "Usage: rsg <path to grammar text file>" << endl;
    return 1; // non-zero return value means something bad happened
  }

  ifstream grammarFile(argv[1]);
  if (grammarFile.fail()) {
    cerr << "Failed to open the file named \"" << argv[1]
         << "\".  Check to ensure the file exists. " << endl;
    return 2; // each bad thing has its own bad return value
  }

  // things are looking good...
  map<string, Definition> grammar;
  readGrammar(grammarFile, grammar);

  Definition start = grammar["<start>"];

  Production startProduction = start.getRandomProduction();

  for (int i = 1; i < 4; i++) {
    cout << "Version " << i << ":" << endl;
    cout << compose(startProduction, grammar) << endl;
    cout << endl;
  }

  return 0;
}
