//
// IOManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src/Manager
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Fri Apr  1 14:22:20 2016 Valerian Polizzi
// Last update Sun Apr  3 13:16:07 2016 Valerian Polizzi
//

#include <IOManager.hh>
#include <ArcadeException.hh>
#include <sstream>
#include <unistd.h>
#include <stdio.h>

IOManager::IOManager(IGame *game)
{
  _game = game;
  this->Read();
}

IOManager::~IOManager()
{

}

void   IOManager::Read()
{
  /*
 char			*buff;
  arcade::CommandType	rtn;

  buff = malloc(16);
  read(0, buff, sizeof(arcade::CommandType));
  rtn = strtol(buff, NULL, 16);
  return (rtn);
  */
}
