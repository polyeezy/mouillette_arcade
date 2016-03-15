//
// AEntity.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:21:24 2016 Valerian Polizzi
// Last update Sat Mar 12 10:48:59 2016 Loïc Weinhard
//

#include <AEntity.hh>

AEntity::AEntity()
{
}

AEntity::AEntity(const float w, const float h, const float x, const float y, const float s)
{
  _size.width = w;
  _size.height = h;
  _pos.x = x;
  _pos.y = y;
  _speed = s;
}

float	AEntity::getWidth() const
{
  return (_size.width);
}

float	AEntity::getHeight() const
{
  return (_size.height);
}

t_size	AEntity::getSize() const
{
  return (_size);
}

float	AEntity::getX() const
{
  return (_pos.x);
}

float	AEntity::getY() const
{
  return (_pos.y);
}

t_pos	AEntity::getPos() const
{
  return (_pos);
}

float	AEntity::getSpeed() const
{
  return (_speed);
}

void	AEntity::setWidth(const float w)
{
  _size.width = w;
}

void	AEntity::setHeight(const float h)
{
  _size.height = h;
}

void	AEntity::setSize(const t_size size)
{
  _size = size;
}

void	AEntity::setX(const float x)
{
  _pos.x = x;
}

void	AEntity::setY(const float y)
{
  _pos.y = y;
}

void	AEntity::setPos(const t_pos pos)
{
  _pos = pos;
}

void	AEntity::setSpeed(const float s)
{
  _speed = s;
}
