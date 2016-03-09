//
// Pacman.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:54:19 2016 Loïc Weinhard
// Last update Wed Mar  9 12:15:50 2016 Loïc Weinhard
//

#ifndef PENTITY_HH_
# define PENTITY_HH_

# include <Protocol.hpp>
# include "AEntity.hh"

class	PEntity : public AEntity
{
private:
  bool	_god;

public:
  PEntity(const arcade::Size, const arcade::Position, const float);
  virtual ~PEntity();
  bool		getGod() const;
  void		setGod(const bool);
};

#endif
