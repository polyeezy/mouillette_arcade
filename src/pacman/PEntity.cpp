//
// PEntity.cpp for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:59:42 2016 Loïc Weinhard
// Last update Wed Mar 30 14:43:22 2016 Miele Alexis
//

#include "PEntity.hh"

PEntity::PEntity(const float w, const float h, const float x, const float y, const float s) : AEntity(w, h, x, y, s)
{
  _god = false;
  _dir = ControllerManager::RIGHT;
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

void	PEntity::move(const PMap *map, const ControllerManager::e_control new_dir)
{
  _dir = new_dir;
  switch (new_dir)
    {
    case ControllerManager::UP:
      this->checkVerticalMove(map, -1);
      break;
    case ControllerManager::DOWN:
      this->checkVerticalMove(map, 1);
      break;
    case ControllerManager::LEFT:
      this->checkHorizontalMove(map, -1);
      break;
    case ControllerManager::RIGHT:
      this->checkHorizontalMove(map, 1);
      break;
    default:
      break;
    };
}

void	PEntity::checkVerticalMove(const PMap *map, const int asc_desc)
{
  float	speed;
  t_pos	new_pos;

  new_pos = this->getPos();
  speed = this->getSpeed();
  while (speed > 0)
    {
      new_pos.y = new_pos.y + (asc_desc * 0.10);
      if (map->getPos(new_pos) == '1' || map->getPos(new_pos) == 'P')
	return;
      this->setY(new_pos.y);
      speed -= 0.10;
    }
}

void	PEntity::checkHorizontalMove(const PMap *map, const int left_right)
{
  float	speed;
  t_pos	new_pos;

  new_pos = this->getPos();
  speed = this->getSpeed();
  while (speed > 0)
    {
      new_pos.x = new_pos.x + (left_right * 0.10);
      if (map->getPos(new_pos) == '1' || map->getPos(new_pos) == 'P')
	return;
      this->setX(new_pos.x);
      speed -= 0.10;
    }
}
