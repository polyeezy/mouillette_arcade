//
// PEntity.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:59:42 2016 Loïc Weinhard
// Last update Wed Mar  9 14:17:46 2016 Loïc Weinhard
//

#include "PEntity.hh"

PEntity::PEntity(const arcade::Size s, const arcade::Position p, const float sp) : AEntity(s, p, sp)
{
  _god = false;
}

PEntity::~PEntity()
{
}

bool	PEntity::getGod() const
{
  return _god;
}

void	PEntity::setGod(const bool god)
{
  _god = god;
}

void	PEntity::print()
{

}
