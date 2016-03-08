//
// AEntity.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:21:24 2016 Valerian Polizzi
// Last update Tue Mar  8 17:03:37 2016 Loïc Weinhard
//

#include <AEntity.hh>

AEntity::AEntity(const arcade::Size size, const arcade::Position pos, const float speed)
{
  _size = size;
  _pos = pos;
  _speed = speed;
}

AEntity::~AEntity()
{
}

arcade::Size	AEntity::getSize() const
{
  return _size;
}

void		AEntity::setPos(const arcade::Position &pos)
{
  _pos = pos;
}

arcade::Position	AEntity::getPos() const
{
  return (_pos);
}
