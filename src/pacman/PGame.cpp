//
// PGame.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Wed Mar  9 14:03:53 2016 Loïc Weinhard
// Last update Wed Mar  9 14:58:05 2016 Loïc Weinhard
//

#include "Protocol.hpp"
#include "PGame.hh"

PGame::PGame(const std::string &file)
{
  arcade::Size		size;
  arcade::Position	pos;
  int			i;

  _map = new Map(file);
  size.width = PENTITY_WIDTH;
  size.height = PENTITY_HEIGHT;
  pos.x = 0;
  pos.y = 0;
  _pacman = new PEntity(size, pos, PENTITY_SPEED);
  i = 0;
  while (i < GHOSTS)
    {
      pos = _map->getNextGhostSpawn();
      _ghosts.push_back(new PEntity(size, pos, PENTITY_SPEED));
      i += 1;
    }
}

void	PGame::Play()
{

}
