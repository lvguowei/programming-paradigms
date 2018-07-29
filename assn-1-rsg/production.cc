#include "production.h"

Production::Production(ifstream &infile) // phrases is constructed, size is 0
{
  while (true) {
    string token;
    infile >> token; // ignores whitespace by default
    if (token == ";")
      break;
    phrases.push_back(token);
  }

  string uselessText;
  getline(infile, uselessText); // read everything else as if it's important
  // oh, no it's not.. it's useless.. but we're glad it's been pulled from the
  // stream..
}
