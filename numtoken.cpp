#include <string>
using namespace std;
#include "numtoken.h"

NumToken::NumToken(){
  set_token_type(TOKEN_NUM);
  attribute = new string("UNDEFINED NUMBER");
}
NumToken::NumToken(const string& attr){
  set_token_type(TOKEN_NUM);
  attribute = new string(attr);
}
NumToken::~NumToken(){
  if (attribute != NULL) {
    delete attribute;
  }
}


string *NumToken::get_attribute() const{
  return new string(*attribute);
}
void NumToken::set_attribute(const string& attr){
  attribute = new string(attr);
}

string *NumToken::to_string() const{
  return new string("Num: " + *attribute);
}

