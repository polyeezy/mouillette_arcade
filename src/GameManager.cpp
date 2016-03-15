//
// GameManager.cpp for  in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar 15 13:57:25 2016 Valerian Polizzi
// Last update Tue Mar 15 14:49:31 2016 Valerian Polizzi
//

#include <GameManager.hh>

GameManager::GameManager()
{
  _games["Snake"] = new Snake();
  _games["Pacman"] = new Snake();
}

GameManager::~GameManager()
{
}

void		GameManager::play(const std::string &game)
{
  _games[game]->play();
}
