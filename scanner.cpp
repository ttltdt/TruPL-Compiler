#include <string>
#include <iostream>
using namespace std;

#include "scanner.h"
#include "buffer.h"
#include "punctoken.h"
#include "addoptoken.h"
#include "eoftoken.h"
#include "idtoken.h"
#include "keywordtoken.h"
#include "muloptoken.h"
#include "numtoken.h"
#include "punctoken.h"
#include "reloptoken.h"


Scanner::Scanner( char * filename )
{
  buf = new Buffer( filename );

}

void Scanner::scanner_fatal_error( const string& mesg )
{
  std::cerr << mesg;
  exit( -1 );
}

Scanner::~Scanner(){
  if(buf != nullptr){
    delete buf;
  }
}

Token *Scanner::next_token()
{
  const int done = -1;
  int state = 0;
  string attr = "";
  Token * tok ;
  while( state != done )
  {
    cout << state << " ";
    char c = buf->next_char();
    switch( state )
    {

    case 0:
      if(c == 'o'){
        state = 1;
        attr += c;
      }else if(c == 'a'){
        state = 2;
        attr += c;
      }else if(c == 'p'){
        state = 4;
        attr += c;
      }else if(c == 'i'){
        state = 15;
        attr += c;
      }else if(c == 'b'){
        state = 17;
        attr += c;
      }else if(c == 'e'){
        state = 23;
        attr += c;
      }else if(c == 't'){
        state = 27;
        attr += c;
      }else if(c == 'w'){
        state = 30;
        attr += c;
      }else if(c == 'l'){
        state = 34;
        attr += c;
      }else if(c == 'n'){
        state = 41;
        attr += c;
      }else if(is_alpha(c)){
        state = 700;
        attr += c;
      }else if(is_digit(c)){
        state = 600;
        attr += c;
      }else if(c == ';'){
        state = PUNC_SEMI;
      }else if(c == ':'){
        state = PUNC_COLON;
      }else if(c == ','){
        state = PUNC_COMMA;
      }else if(c == '('){
        state = PUNC_OPEN;
      }else if(c == ')'){
        state = PUNC_CLOSE;
      }else if(c == '='){
        state = RELOP_EQ;
      }else if(c == '<'){
        state = RELOP_LT;
      }else if(c == '>'){
        state = RELOP_GT;
      }else if(c == '+'){
        state = ADDOP_ADD;
      }else if(c == '-'){
        state = ADDOP_SUB;
      }else if(c == '*'){
        state = MULOP_MUL;
      }else if(c == '/'){
        state = MULOP_DIV;
      }else if(c == '$'){
        state = done;
        tok = new EofToken();
      }else{
        scanner_fatal_error("Error at state 0");
      }
      break;

    case 1:
      if(c == 'r'){
        state = ADDOP_OR;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 2:
      if(c == 'n'){
        state = 3;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 3:
      if(c == 'd'){
        state = MULOP_AND;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 4:
      if(c == 'r'){
        state = 5;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 5:
      if(c == 'o'){
        state = 6;
        attr += c;
      }else if(c == 'i'){
        state = 39;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 6:
      if(c == 'g'){
        state = 7;
        attr += c;
      }else if(c == 'c'){
        state = 10;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 7:
      if(c == 'r'){
        state = 8;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 8:
      if(c == 'a'){
        state = 9;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 9:
      if(c == 'm'){
        state = KW_PROGRAM;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 10:
      if(c == 'e'){
        state = 11;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 11:
      if(c == 'd'){
        state = 12;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 12:
      if(c == 'u'){
        state = 13;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 13:
      if(c == 'r'){
        state = 14;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 14:
      if(c == 'e'){
        state = KW_PROCEDURE;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 39:
      if(c == 'n'){
        state = 40;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 40:
      if(c == 't'){
        state = KW_PRINT;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;

    case 15:
      if(c == 'n'){
        state = 16;
        attr += c;
      }else if(c == 'f'){
        state = KW_IF;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 16:
      if(c == 't'){
        state = KW_INT;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 17:
      if(c == 'o'){
        state = 18;
        attr += c;
      }else if(c == 'e'){
        state = 20;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 18:
      if(c == 'o'){
        state = 19;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 19:
      if(c == 'l'){
        state = KW_BOOL;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 20:
      if(c == 'g'){
        state = 21;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 21:
      if(c == 'i'){
        state = 22;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 22:
      if(c == 'n'){
        state = KW_BEGIN;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 23:
      if(c == 'n'){
        state = 24;
        attr += c;
      }else if(c == 'l'){
        state = 25;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 24:
      if(c == 'd'){
        state = KW_END;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 25:
      if(c == 's'){
        state = 26;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 26:
      if(c == 'e'){
        state = KW_ELSE;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 27:
      if(c == 'h'){
        state = 28;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 28:
      if(c == 'e'){
        state = 29;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 29:
      if(c == 'n'){
        state = KW_THEN;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 30:
      if(c == 'h'){
        state = 31;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 31:
      if(c == 'i'){
        state = 32;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 32:
      if(c == 'l'){
        state = 33;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 33:
      if(c == 'e'){
        state = KW_WHILE;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 34:
      if(c == 'o'){
        state = 35;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 35:
      if(c == 'o'){
        state = 36;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 36:
      if(c == 'p'){
        state = KW_LOOP;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;

    case 41:
      if(c == 'o'){
        state = 42;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 42:
      if(c == 't'){
        state = KW_NOT;
        attr += c;
      }else if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;

    case ADDOP_OR:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new AddopToken(ADDOP_OR);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case MULOP_AND:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new MulopToken(MULOP_AND);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_PROGRAM:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_PROGRAM);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;

    case KW_PROCEDURE:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_PROCEDURE);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_PRINT:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_PRINT);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_INT:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_INT);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_IF:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_IF);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_BOOL:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_BOOL);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_BEGIN:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_BEGIN);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_END:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_END);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_ELSE:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_ELSE);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_THEN:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_THEN);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_WHILE:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_WHILE);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_LOOP:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_LOOP);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case KW_NOT:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else{
        tok = new KeywordToken(KW_NOT);
        state = done;
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case PUNC_SEMI:
      tok = new PuncToken(PUNC_SEMI);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case PUNC_COLON:
      if(c == '='){
        state = PUNC_ASSIGN;
      }else{
        tok = new PuncToken(PUNC_COLON);
        state = done;
        if(!is_space(c))
        {
          buf->unread_char(c);
        }
      }
      break;
    case PUNC_ASSIGN:
      tok = new PuncToken(PUNC_ASSIGN);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;

    case PUNC_COMMA:
      tok = new PuncToken(PUNC_COMMA);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case PUNC_CLOSE:
      tok = new PuncToken(PUNC_CLOSE);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case PUNC_OPEN:
      tok = new PuncToken(PUNC_OPEN);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case RELOP_EQ:
      tok = new RelopToken(RELOP_EQ);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case RELOP_LT:
      if(c == '>'){
        state = RELOP_NE;
      }else if(c == '='){
        state = RELOP_LE;
      }else{
        tok = new RelopToken(RELOP_LT);
        state = done;
        if(!is_space(c))
        {
          buf->unread_char(c);
        }
      }
      break;
    case RELOP_NE:
      tok = new RelopToken(RELOP_NE);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case RELOP_LE:
      tok = new RelopToken(RELOP_LE);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case RELOP_GT:
      if(c == '='){
        state = RELOP_GE;
      }else{
        tok = new RelopToken(RELOP_GT);
        state = done;
        if(!is_space(c))
        {
          buf->unread_char(c);
        }
      }
      break;
    case RELOP_GE:
      tok = new RelopToken(RELOP_GE);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case ADDOP_ADD:
      tok = new AddopToken(ADDOP_ADD);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;

    case ADDOP_SUB:
      tok = new AddopToken(ADDOP_SUB);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case MULOP_MUL:
      tok = new MulopToken(MULOP_MUL);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    case MULOP_DIV:
      tok = new MulopToken(MULOP_DIV);
      state = done;
      if(!is_space(c))
      {
        buf->unread_char(c);
      }
      break;
    //number
    case 600:
      if(is_digit(c)){
        state = 600;
        attr += c;
      }else{
        state = done;
        tok = new NumToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    case 700:
      if(is_alphanum(c)){
        state = 700;
        attr += c;
      }else {
        state = done;
        tok = new IdToken(attr);
        if(!is_space(c)){
          buf->unread_char(c);
        }
      }
      break;
    default:
      scanner_fatal_error("invalid char in the buffer while scanning");
      break;
    }
  }
  return tok;
}




