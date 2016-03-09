//
// Pacman.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:59:42 2016 Loïc Weinhard
// Last update Tue Mar  8 17:04:15 2016 Loïc Weinhard
//

#include "Pacman.hh"

Pacman::Pacman(const arcade::Size s, const arcade::Position p, const float sp) : AEntity(s, p, sp)
{
  _god = false;
}

Pacman::~Pacman()
{
}

bool	Pacman::getGod() const
{
  return _god;
}

void	Pacman::setGod(const bool god)
{
  _god = god;
}
