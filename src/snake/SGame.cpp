//
// SGame.cpp for SGame in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 17:50:32 2016 Miele Alexis
// Last update Sun Apr  3 14:56:27 2016 Miele Alexis
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
  _gm->setTexture('x', std::string(SNAKE_PATH).append("grass.jpg"));
  _gm->setTexture('0', std::string(SNAKE_PATH).append("cookie.png"));
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
  std::vector<t_snakebody *> body;

  pos = _map->getSpawn();
  _snake = new SEntity(SENTITY_WIDTH, SENTITY_HEIGHT, pos, SENTITY_SPEED);
  std::cout << "SNAKE CREATED" << std::endl;
  control = -1;
  _snake->newBody();
  _snake->newBody();
  _snake->newBody();
  _map->setGum(_snake);
  while (control != ControllerManager::ESCAPE && _snake->getAlive())
    {
      control = this->getGM()->getKey();
      body = _snake->getBody();
      // if (!body.empty())
      // 	_map->setElem((*body.end())->pos, 'x');
      _map->setElem(_snake->getPos(), 'x');
      this->move(control);
      body = _snake->getBody();
      // if (!body.empty())
      // 	for(std::vector<t_snakebody *>::iterator itr = body.begin(); itr != body.end(); itr++)
      // 	  _map->setElem((*itr)->pos, '*');
      if (_map->getPos(_snake->getPos()) == '0')
	{
	  _snake->newBody();
	  _map->setGum(_snake);
	}
      _map->setElem(_snake->getPos(), '#');
      this->getGM()->print(this->getMap());
    }

}

extern "C" IGame *createIGame()
{
  return (new SGame);
}
