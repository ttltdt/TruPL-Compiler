#include <string>
using namespace std;
#include "muloptoken.h"

MulopToken::MulopToken(){
    set_token_type(TOKEN_MULOP);
    attribute = MULOP_NO_ATTR;
}

MulopToken::MulopToken(const mulop_attr_type attr){
    set_token_type(TOKEN_MULOP);
    attribute = attr;

}

MulopToken::~MulopToken(){
}

mulop_attr_type MulopToken::get_attribute (){
    return attribute;
}

void MulopToken::set_attribute (const mulop_attr_type attr){
    attribute = attr;
}

string *MulopToken::to_string() const{
    string attribute_name;

    switch (attribute)
    {
    case MULOP_AND:
        attribute_name = "And";
        break;
    case MULOP_DIV:
        attribute_name = "Divide";
        break;
    case MULOP_MUL:
        attribute_name = "Multiply";
        break;
    case MULOP_NO_ATTR:
        attribute_name = "No Attribute";
        break;
    default:
        attribute_name = "GARBAGE ATTRIBUTE VALUE";
        break;
    }
    return new string("Multiplication Operation: " + attribute_name);

}

