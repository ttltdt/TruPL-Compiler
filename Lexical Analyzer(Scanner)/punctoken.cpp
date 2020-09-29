#include <string>
using namespace std;

#include "token.h"
#include "punctoken.h"

/* Create a new token with no attributes. */
PuncToken::PuncToken()
{
    set_token_type(TOKEN_PUNC);
    attribute = PUNC_NO_ATTR;
}

PuncToken::~PuncToken(){
}

PuncToken::PuncToken(punc_attr_type attr)
{
    set_token_type(TOKEN_PUNC);
    attribute = attr;
}

punc_attr_type PuncToken::get_attribute() const
{
    return attribute;
}
void PuncToken::set_attribute (const punc_attr_type type)
{
    attribute = type;
}

string *PuncToken::to_string() const
{
    string attribute_name;

    switch (attribute)
    {
    case PUNC_SEMI:
        attribute_name = "Semi Colon";
        break;
    case PUNC_CLOSE:
        attribute_name = "Close Parentheses";
        break;
    case PUNC_COLON:
        attribute_name = "Colon";
        break;
    case PUNC_COMMA:
        attribute_name = "Comma";
        break;
    case PUNC_OPEN:
        attribute_name = "Open Parentheses";
        break;
    case PUNC_NO_ATTR:
        attribute_name = "NO ATTRIBUTE";
        break;
    case PUNC_ASSIGN:
        attribute_name = "Assignment";
        break;
    default:
        attribute_name = "GARBAGE ATTRIBUTE VALUE";
        break;
    }
    return new string("Punctuation: " + attribute_name);
}
