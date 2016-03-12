//
// PEntity.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:59:42 2016 Loïc Weinhard
// Last update Sat Mar 12 13:34:54 2016 Loïc Weinhard
//

#include "PEntity.hh"

PEntity::PEntity(const float w, const float h, const float x, const float y, const float s) : AEntity(w, h, x, y, s)
{
  _god = false;
  _dir = RIGHT;
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

void	PEntity::move(const Map *map, const e_dir new_dir)
{
  _dir = new_dir;
  switch (new_dir)
    {
    case UP:
      this->setPos(this->checkVerticalMove(map, -1));
      break;
    case DOWN:
      this->setPos(this->checkVerticalMove(map, 1));
      break;
    case LEFT:
      this->setPos(this->checkHorizontalMove(map, -1));
      break;
    case RIGHT:
      this->setPos(this->checkHorizontalMove(map, 1));
      break;
    };
}

t_pos	PEntity::checkVerticalMove(const Map *map, const int asc_desc)
{
  float	speed;
  t_pos	new_pos;

  new_pos = this->getPos();
  speed = this->getSpeed();
  while (speed > 0)
    {
      new_pos.y = new_pos.y + (asc_desc * 0.10);
      if (new_pos.y == (int)new_pos.y && map->getPos(new_pos) != '1')
	this->setY(new_pos.y);
      else
	return (this->getPos());
      speed -= 0.10;
    }
  return (this->getPos());
}

t_pos	PEntity::checkHorizontalMove(const Map *map, const int left_right)
{
  float	speed;
  t_pos	new_pos;

  new_pos = this->getPos();
  speed = this->getSpeed();
  while (speed > 0)
    {
      new_pos.x = new_pos.x + (left_right * 0.10);
      if (new_pos.x == (int)new_pos.x && map->getPos(new_pos) != '1')
	this->setX(new_pos.x);
      else
	return (this->getPos());
      speed -= 0.10;
    }
  return (this->getPos());
}
