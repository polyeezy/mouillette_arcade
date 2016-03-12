//
// AEntity.hh for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:16:58 2016 Valerian Polizzi
// Last update Sat Mar 12 10:49:07 2016 Loïc Weinhard
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <string>
# include "Size.hh"
# include "Position.hh"

class AEntity
{
private:
  t_size	_size;
  t_pos		_pos;
  float		_speed;

public:
  AEntity();
  AEntity(const float, const float, const float, const float, const float);
  float		getWidth() const;
  float		getHeight() const;
  t_size	getSize() const;
  float		getX() const;
  float		getY() const;
  t_pos		getPos() const;
  float		getSpeed() const;
  void		setWidth(const float);
  void		setHeight(const float);
  void		setSize(const t_size);
  void		setX(const float);
  void		setY(const float);
  void		setPos(const t_pos);
  void		setSpeed(const float);
  ~AEntity() {};
};

#endif
