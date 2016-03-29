//
// SGame.cpp for SGame in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 17:50:32 2016 Miele Alexis
// Last update Tue Mar 29 23:50:27 2016 Miele Alexis
//

#include "Protocol.hpp"
#include "SGame.hh"
#include "Position.hh"

SGame::SGame()
{
  std::cout << "PACMAN CONSTRUCTOR" << std::endl;
}

SGame::SGame(const size_t &size)
{
  t_pos			pos;

  _map = new SMap(size);
  pos = _map->getSpawn();
  _snake = new SEntity(SENTITY_WIDTH, SENTITY_HEIGHT, pos, SENTITY_SPEED);
}

void	SGame::move(const ControllerManager::e_control dir)
{
  _snake->move(_map, dir);
}

SMap&	SGame::getMap() const
{
  return (*_map);
}

void	SGame::play()
{
}

extern "C" IGame *createIGame()
{
  return (new SGame);
}
