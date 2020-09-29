#include <iostream>
#include <cstdlib>
using namespace std;

#include "token.h"
#include "keywordtoken.h"
#include "punctoken.h"
#include "reloptoken.h"
#include "addoptoken.h"
#include "muloptoken.h"
#include "idtoken.h"
#include "numtoken.h"
#include "eoftoken.h"

#include "scanner.h"

/* A program to print all the TruPL tokens and their attributes in
   a file.
*/
int main (int argc, char **argv)
{

  char *filename;

  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <input file name>" << endl;
    exit (-1);
  }

  filename = argv[1];

  // Declare a Scanner object and a pointer to a Token object.
  Scanner s(filename);
  Token *t = NULL;

  // Grab and print tokens until the EOF token is returned.
  do {
    if (t != NULL) {
      delete t;
    }

    t = s.next_token();

    // Print out the token type and its attribute, if any.
    if (t->get_token_type() == TOKEN_NO_TYPE) {
      cout << "Error: next_token() returned typeless token." << endl;
    } else {
      /* to_string() is a method that every token type class should
	 have.  It converts the token's internal representation to a
	 human readable form. */
      cout << *(t->to_string()) << endl;
    }

  } while (t->get_token_type() != TOKEN_EOF);

}


