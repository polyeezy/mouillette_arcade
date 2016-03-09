//
// AEntity.hh for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:16:58 2016 Valerian Polizzi
// Last update Tue Mar  8 17:03:46 2016 Loïc Weinhard
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <string>
# include <Protocol.hpp>

class AEntity
{
private:
  arcade::Size		_size;
  arcade::Position	_pos;
  float			_speed;
public:
  AEntity(const arcade::Size, const arcade::Position, const float);
  virtual ~AEntity();
  arcade::Size	getSize() const;
  virtual void	print()  = 0;
  void		setPos(const arcade::Position&);
  arcade::Position	getPos() const;
};

#endif
