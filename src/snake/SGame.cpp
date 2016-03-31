//
// SGame.cpp for SGame in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 17:50:32 2016 Miele Alexis
// Last update Wed Mar 30 15:27:56 2016 Miele Alexis
//

#include "Protocol.hpp"
#include "SGame.hh"
#include "Position.hh"

SGame::SGame()
{
  std::cout << "PACMAN CONSTRUCTOR" << std::endl;
}

SGame::SGame(const std::string &map)
{
  t_pos			pos;

  _map = new SMap(map);
  pos = _map->getSpawn();
  _snake = new SEntity(SENTITY_WIDTH, SENTITY_HEIGHT, pos, SENTITY_SPEED);
}

void	SGame::setMap(const std::string &map)
{
  _map = new SMap(map);
}

void            SGame::setGM(IGraphicManager *gm)
{
  _gm = gm;
}

IGraphicManager *SGame::getGM()
{
  return (_gm);
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
