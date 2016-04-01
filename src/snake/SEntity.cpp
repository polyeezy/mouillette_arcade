//
// SEntity.cpp for SEntity in /home/miele_a/rendu/arcade/mouillette_arcade/src/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 16:18:20 2016 Miele Alexis
// Last update Fri Apr  1 10:59:29 2016 Miele Alexis
//

#include "SEntity.hh"

SEntity::SEntity(const float w, const float h, const float x, const float y, const float s) : AEntity(w, h, x, y, s)
{
  _alive = true;
  _dir = 0;
}

SEntity::SEntity(const float w, const float h, const t_pos p, const float s) : AEntity(w, h, p.x, p.y, s)
{
  _alive = true;
  _dir = 0;
}

SEntity::~SEntity()
{
}

void	SEntity::print()
{

}

void	SEntity::move(const SMap *map, const int new_dir)
{
  if (new_dir != 0)
    _dir = new_dir;
  switch (_dir)
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

void	SEntity::checkVerticalMove(const SMap *map, const int asc_desc)
{
  float	speed;
  t_pos	new_pos;

  new_pos = this->getPos();
  speed = this->getSpeed();
  while (speed > 0)
    {
      new_pos.y = new_pos.y + (asc_desc * 0.05);
      if (new_pos.y > map->getSize() || new_pos.y < 0)
	{
	  _alive = false;
	  return;
	}
      // if (!_body.empty())
      // 	{
      // 	  for (size_t i = 0; i < _body.size(); i++)
      // 	    {
      // 	      if (new_pos.y == _body[i]->pos.y && new_pos.x == _body[i]->pos.x)
      // 		{
      // 		  _alive = false;
      // 		  return;
      // 		}
      // 	      _body[i]->pos.y = _body[i]->pos.y + (asc_desc * 0.10);
      // 	    }
      // 	}
      this->setY(new_pos.y);
      speed -= 0.1;
    }
}

void	SEntity::checkHorizontalMove(const SMap *map, const int left_right)
{
  float	speed;
  t_pos	new_pos;

  new_pos = this->getPos();
  speed = this->getSpeed();
  while (speed > 0)
    {
      new_pos.x = new_pos.x + (left_right * 0.05);
      if (new_pos.x > map->getSize() || new_pos.x < 0)
	{
	  _alive = false;
	  return;
	}
      // if (!_body.empty())
      // 	{
      // 	  for (size_t i = 0; i < _body.size(); i++)
      // 	    {
      // 	      if (new_pos.y == _body[i]->pos.y && new_pos.x == _body[i]->pos.x)
      // 		{
      // 		  _alive = false;
      // 		  return;
      // 		}
      // 	      _body[i]->pos.x = _body[i]->pos.x + (left_right * 0.10);
      // 	    }
      // 	}
      this->setX(new_pos.x);
      speed -= 0.1;
    }
}

void	SEntity::newBody()
{
  t_pos	pos = this->getPos();
  t_snakebody *newBody = new t_snakebody;

  newBody->pos.x = pos.x;
  newBody->pos.y = pos.y;
  _body.push_back(newBody);
}

const bool &SEntity::getAlive() const
{
  return _alive;
}

const std::vector<t_snakebody*> &SEntity::getBody() const
{
  return _body;
}
