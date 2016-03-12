//
// PEntity.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:59:42 2016 Loïc Weinhard
// Last update Sat Mar 12 09:54:28 2016 Loïc Weinhard
//

#include "PEntity.hh"

PEntity::PEntity(const float w, const float h, const float x, const float y, const float s) : AEntity(w, h, x, y, s)
{
  _god = false;
}

PEntity::PEntity(const float w, const float h, const t_pos p, const float s) : AEntity(w, h, p.x, p.y, s)
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
