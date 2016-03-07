//
// AEntity.hh for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Mon Mar  7 14:16:58 2016 Valerian Polizzi
// Last update Mon Mar  7 15:41:15 2016 Valerian Polizzi
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <string>
# include <Protocol.hpp>

class AEntity
{
private:
  size_t		_h;
  size_t		_w;
  arcade::Position	_pos;
public:
  //  AEntity(const size_t height, const size_t width);
  //AEntity(const AEntity&);
  AEntity();
  virtual ~AEntity();
  void		setHeight(const size_t);
  void		setWidth(const size_t);
  size_t	getHeight() const;
  size_t	getWidth() const;
  virtual void	print()  = 0;
  void		setPos(const arcade::Position&);
  arcade::Position	getPos() const;
};

#endif
