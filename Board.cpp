#include "Board.hpp"
#include <iostream>

void ariel::Board::post ( unsigned int row , unsigned int column, Direction dir, std::string str){
  if(dir == ariel::Direction::Horizontal){
    if(column+str.length()> ariel::SIZE)
    {
      //throw"post command is out of bounds!";
    }
    else{
      for(unsigned int i = 0; i<str.length(); i++){
        this->board[row][column+i] = str.at(i);
      }
    }
  }
  else{
    if(row+str.length()> ariel::SIZE)
    {
      //throw"post command is out of bounds!";
    }
    else{
    for(unsigned int i = 0; i<str.length(); i++){
      this->board[row+i][column] = str.at(i);
      }    
  }
  }
}

std::string ariel::Board::read (unsigned int row , unsigned int column, Direction dir, unsigned int len){
    std::string s = "";
  if(dir == ariel::Direction::Horizontal){
    for(unsigned int i = 0;i<len;i++){
      s = s+ this->board[row][column+i];
    }
  }
  else{
    for(unsigned int i = 0;i<len;i++){
      s = s+ this->board[row+i][column];
    }    
  }
  return s;
}

 void ariel::Board::show(){
  for(int i=0 ; i < ariel::SIZE ;i++){
    for(int j=0 ; j < ariel::SIZE ;j++){
      cout<< this->board[i][j]; 
    }
    cout<<"\n";
  }

}

ariel::Board::Board(){
   for(int i=0 ; i < ariel::SIZE ;i++){
    for(int j=0 ; j < ariel::SIZE ;j++){
      board[i][j]='_'; 
    }
  }
}

