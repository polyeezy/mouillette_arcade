//
// SGame.cpp for SGame in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 17:50:32 2016 Miele Alexis
// Last update Fri Apr  1 10:35:35 2016 Miele Alexis
//

#include "Protocol.hpp"
#include "SGame.hh"
#include "Position.hh"

SGame::SGame()
{
  std::cout << "PACMAN CONSTRUCTOR" << std::endl;
  this->setMap("level_1.snake");
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

void	SGame::move(const int dir)
{
  _snake->move(_map, dir);
}

SMap&	SGame::getMap() const
{
  return (*_map);
}

void	SGame::play()
{
  t_pos	pos;
  int	control;

  pos = _map->getSpawn();
  _snake = new SEntity(SENTITY_WIDTH, SENTITY_HEIGHT, pos, SENTITY_SPEED);
  std::cout << "SNAKE CREATED" << std::endl;
  control = -1;
  while (control != ControllerManager::ESCAPE && _snake->getAlive())
    {
      control = this->getGM()->getKey();
      _map->setElem(_snake->getPos(), 'x');
      this->move(control);
      _map->setElem(_snake->getPos(), '#');
      this->getGM()->print(this->getMap());
    }

}

extern "C" IGame *createIGame()
{
  return (new SGame);
}
