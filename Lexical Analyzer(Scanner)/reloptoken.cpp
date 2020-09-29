#include <string>
using namespace std;
#include "reloptoken.h"

RelopToken::RelopToken(){
    set_token_type(TOKEN_RELOP);
    attribute = RELOP_NO_ATTR;
}

RelopToken::RelopToken(const relop_attr_type attr){
    set_token_type(TOKEN_RELOP);
    attribute = attr;
}

RelopToken::~RelopToken(){
}

relop_attr_type RelopToken::get_attribute() const{
    return attribute;
}

void RelopToken::set_attribute(const relop_attr_type attr){
    attribute = attr;
}

string *RelopToken::to_string() const{
    string attribute_name;

    switch (attribute)
    {
    case RELOP_EQ:
        attribute_name = "Equal";
        break;
    case RELOP_NE:
        attribute_name = "Not Equal";
        break;
    case RELOP_GT:
        attribute_name = "Greater Than";
        break;
    case RELOP_GE:
        attribute_name = "Greater or Equal";
        break;
    case RELOP_LT:
        attribute_name = "Less Than";
        break;
    case RELOP_LE:
        attribute_name = "Less Than or Equal";
        break;
    case RELOP_NO_ATTR:
        attribute_name = "No Attribute";
        break;
    default:
        attribute_name = "GARBAGE ATTRIBUTE VALUE";
        break;
    }
    return new string("Relational Operation: " + attribute_name);
}
