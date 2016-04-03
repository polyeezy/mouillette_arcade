//
// IOManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include/Manager
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Fri Apr  1 14:20:53 2016 Valerian Polizzi
// Last update Sun Apr  3 12:43:54 2016 Valerian Polizzi
//

#ifndef _IOMANAGER_HH_
# define _IOMANAGER_HH_

#include <Protocol.hpp>
#include <string>
#include <iostream>
#include <stdlib.h>
//#include <IGame.hpp>

class IGame;

class IOManager
{
  std::string _lastCmd;
  IGame		*_game;
public:
  IOManager(IGame *);
  ~IOManager();
  void Read();
};

#endif
