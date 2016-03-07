//
// AEntity.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:21:24 2016 Valerian Polizzi
// Last update Mon Mar  7 15:55:50 2016 Valerian Polizzi
//

#include <AEntity.hh>

AEntity::AEntity()
{
}

AEntity::~AEntity()
{
}

size_t		AEntity::getHeight() const
{
  return (_h);
}


size_t		AEntity::getWidth() const
{
  return (_w);
}

void		AEntity::setPos(const arcade::Position &pos)
{
  _pos = pos;
}

arcade::Position	AEntity::getPos() const
{
  return (_pos);
}
