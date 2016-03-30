//
// PGame.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Wed Mar  9 14:03:53 2016 Loïc Weinhard
// Last update Wed Mar 30 15:11:36 2016 Miele Alexis
//

#include "Protocol.hpp"
#include "PGame.hh"
#include "Position.hh"

PGame::PGame()
{
  std::cout << "PACMAN CONSTRUCTOR" << std::endl;
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

void	PGame::move(const ControllerManager::e_control dir)
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

  pos = _map->getPacmanSpawn();
  _pacman = new PEntity(PENTITY_WIDTH, PENTITY_HEIGHT, pos, PENTITY_SPEED);
  i = 0;
  while (i < GHOSTS)
    {
      pos = _map->getNextGhostSpawn();
         _ghosts.push_back(new PEntity(PENTITY_WIDTH, PENTITY_HEIGHT, pos, PENTITY_SPEED));
      i += 1;
    }
}

extern "C" IGame *createIGame()
{
  return (new PGame);
}
