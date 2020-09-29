#include <list>
#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;

#include "buffer.h"

const char Buffer::EOF_MARKER = '$';      // $
const char Buffer::COMMENT_MARKER = '#';  // #
const char Buffer::SPACE = ' ';           // ' '
const char Buffer::TAB = '\t';             // \t
const char Buffer::NEW_LINE = '\n';        // \n
void Buffer::buffer_fatal_error() const{
}

void Buffer::fill_buf(){

  char c;
  while(source_file.get(c)){
    if(c == COMMENT_MARKER){
      source_file.ignore(std::numeric_limits<streamsize>::max(), NEW_LINE);
    }
    else if(is_whitespace(c)){
      if(!is_whitespace(b.back())){
        b.push_back(SPACE);
      }
    }else{
      b.push_back(c);
    }
  }

  b.push_back('$');

}


// For debugging: dump the current contents of the buffer.  You may
// or may not find this useful.
void Buffer::dump_b(){
  for(auto i: b){
    cout << i;
  }
}


// Open the program file and initialize the scanner buffer.
Buffer::Buffer( char *filename ){
  source_file.open(filename,ifstream::in);
  fill_buf();
  //remove leading white space in the buffer
  if(is_whitespace(b.front())){
    b.pop_front();
  }
}

// Close the file and cleanup.
Buffer::~Buffer(){
  if(source_file.is_open()){
    source_file.close();
  }
}

// Remove the next character from the buffer and
// return it.
char Buffer::next_char(){
  if(b.empty()){
    buffer_fatal_error();
    exit(-1);
    return ' ';
  }
  char next = b.front();
  b.pop_front();
  return next;
}

// Put a character back at the front of the buffer.
void Buffer::unread_char ( char c ){
  b.push_front(c);
}
