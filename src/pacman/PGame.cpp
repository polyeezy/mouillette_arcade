//
// PGame.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Wed Mar  9 14:03:53 2016 Loïc Weinhard
// Last update Mon Mar 21 10:53:09 2016 Loïc Weinhard
//

#include "Protocol.hpp"
#include "PGame.hh"
#include "Position.hh"

PGame::PGame(const std::string &file)
{
  int			i;
  t_pos			pos;

  _map = new Map(file);
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

void	PGame::move(const ControllerManager::e_control dir)
{
  _pacman->move(_map, dir);
  _map->deleteObj(_pacman->getPos());
}

Map&	PGame::getMap() const
{
  return (*_map);
}
