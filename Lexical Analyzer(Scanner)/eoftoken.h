#ifndef EOFTOKEN_H
#define EOFTOKEN_H

#include <string>
using namespace std;

#include "token.h"

class EofToken : public Token
{
 public:
  EofToken ();
  ~EofToken ();

  string *to_string() const;

};

#endif


