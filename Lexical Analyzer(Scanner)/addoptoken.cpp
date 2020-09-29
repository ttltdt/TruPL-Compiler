#include <string>
using namespace std;
#include <string>
#include "addoptoken.h"

AddopToken::AddopToken(){
    set_token_type(TOKEN_ADDOP);
    attribute = ADDOP_NO_ATTR;
}
AddopToken::AddopToken(const addop_attr_type attr){
    set_token_type(TOKEN_ADDOP);
    attribute = attr;

}
AddopToken::~AddopToken(){
}

addop_attr_type AddopToken::get_attribute() const{
    return attribute;
}

void AddopToken::set_attribute (const addop_attr_type attr){
    attribute = attr;
}

string *AddopToken::to_string() const{
    string attribute_name;

    switch (attribute)
    {
    case ADDOP_ADD:
        attribute_name = "Add";
        break;
    case ADDOP_OR:
        attribute_name = "Or";
        break;
    case ADDOP_SUB:
        attribute_name = "Subtract";
        break;
    case ADDOP_NO_ATTR:
        attribute_name = "No Attribute";
        break;
    default:
        attribute_name = "GARBAGE ATTRIBUTE VALUE";
        break;
    }
    return new string("Multiplication Operation: " + attribute_name);
}

