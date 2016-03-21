//
// Pacman.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:54:19 2016 Loïc Weinhard
// Last update Mon Mar 21 10:37:49 2016 Loïc Weinhard
//

#ifndef PENTITY_HH_
# define PENTITY_HH_

# include <Protocol.hpp>
# include "ControllerManager.hh"
# include "map.hh"
# include "AEntity.hh"
# include "Position.hh"

class	PEntity : public AEntity
{
private:
  bool				_god;
  ControllerManager::e_control	_dir;

public:
  PEntity(const float, const float, const float, const float, const float);
  PEntity(const float, const float, const t_pos, const float);
  virtual ~PEntity();
  bool			getGod() const;
  void			setGod(const bool);
  void			move(const Map *, const ControllerManager::e_control);
  void			checkVerticalMove(const Map *, const int);
  void			checkHorizontalMove(const Map *, const int);
  virtual void		print();
};

#endif
