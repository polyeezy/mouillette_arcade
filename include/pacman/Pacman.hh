//
// Pacman.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:54:19 2016 Loïc Weinhard
// Last update Tue Mar  8 17:48:48 2016 Loïc Weinhard
//

#ifndef PACMAN_HH_
# define PACMAN_HH_

# include <Protocol.hpp>
# include "AEntity.hh"

class	Pacman : public AEntity
{
private:
  bool	_god;

public:
  Pacman(const arcade::Size, const arcade::Position, const float);
  virtual ~Pacman();
  bool		getGod() const;
  void		setGod(const bool);
};

#endif
