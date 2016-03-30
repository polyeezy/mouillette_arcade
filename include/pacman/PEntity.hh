//
// Pacman.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:54:19 2016 Loïc Weinhard
// Last update Wed Mar 30 16:44:54 2016 Valerian Polizzi
//

#ifndef PENTITY_HH_
# define PENTITY_HH_

# include <Protocol.hpp>
# include "ControllerManager.hh"
# include "PMap.hh"
# include "AEntity.hh"
# include "Position.hh"

class	PEntity : public AEntity
{
private:
  bool				_god;
  int	_dir;

public:
  PEntity(const float, const float, const float, const float, const float);
  PEntity(const float, const float, const t_pos, const float);
  virtual ~PEntity();
  bool			getGod() const;
  void			setGod(const bool);
  void			move(const PMap *, const int);
  void			checkVerticalMove(const PMap *, const int);
  void			checkHorizontalMove(const PMap *, const int);
  virtual void		print();
};

#endif
