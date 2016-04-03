//
// PGame.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Wed Mar  9 14:03:53 2016 Loïc Weinhard
// Last update Fri Apr  1 16:40:53 2016 Valerian Polizzi
//

#include "Protocol.hpp"
#include "PGame.hh"
#include "Position.hh"
#include <unistd.h>

PGame::PGame()
{
  std::cout << "PACMAN CONSTRUCTOR" << std::endl;
  this->setMap("level_1.pacman");
}

void		PGame::setGM(IGraphicManager *gm)
{
  _gm = gm;
}

IGraphicManager	*PGame::getGM()
{
  return (_gm);
}

void PGame::setMap(const std::string &map)
{
    _map = new PMap(map);
}

PGame::PGame(const std::string &file)
{
  int			i;
  t_pos			pos;

  _map = new PMap(file);
  pos = _map->getPacmanSpawn();
  // _pacman = new PEntity(PENTITY_WIDTH, PENTITY_HEIGHT, pos, PENTITY_SPEED);
  i = 0;
  while (i < GHOSTS)
    {
      pos = _map->getNextGhostSpawn();
      //   _ghosts.push_back(new PEntity(PENTITY_WIDTH, PENTITY_HEIGHT, pos, PENTITY_SPEED));
      i += 1;
    }
}

void	PGame::move(const int dir)
{
  _pacman->move(_map, dir);
  _map->deleteObj(_pacman->getPos());
}

PMap&	PGame::getMap() const
{
  return (*_map);
}

void	PGame::play()
{
  int			i;
  t_pos			pos;
  int			control;

  pos = _map->getPacmanSpawn();
  _pacman = new PEntity(PENTITY_WIDTH, PENTITY_HEIGHT, pos, PENTITY_SPEED);
  std::cout << "PACMAN CREATED" << std::endl;
  i = 0;
  while (i < GHOSTS)
    {
      pos = _map->getNextGhostSpawn();
      _ghosts.push_back(new PEntity(PENTITY_WIDTH, PENTITY_HEIGHT, pos, PENTITY_SPEED));
      i += 1;
      std::cout << "GHOST CREATED [" << i << "]" <<  std::endl;
    }
  _map->setElem(_pacman->getPos(), '#');
  control = -1;
  while (control != ControllerManager::ESCAPE && this->getMap().hasGums())
    {
      control = this->getGM()->getKey();
      _map->setElem(_pacman->getPos(), 'x');
      this->move(control);
      _map->setElem(_pacman->getPos(), '#');
      this->getGM()->print(this->getMap());
    }
}

PEntity&	PGame::getPacman() const
{
  return (*_pacman);
}

extern "C" IGame *createIGame()
{
  return (new PGame);
}

extern "C" void		Play()
{
  IGame		*pacman = createIGame();

  IOManager	IO(pacman);
}
