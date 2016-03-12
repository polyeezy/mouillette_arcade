//
// Pacman.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:54:19 2016 Loïc Weinhard
// Last update Sat Mar 12 13:32:35 2016 Loïc Weinhard
//

#ifndef PENTITY_HH_
# define PENTITY_HH_

# include <Protocol.hpp>
# include "map.hh"
# include "AEntity.hh"
# include "Position.hh"

enum e_dir
  {
    UP, DOWN, LEFT, RIGHT
  };

class	PEntity : public AEntity
{
private:
  bool			_god;
  e_dir			_dir;

public:
  PEntity(const float, const float, const float, const float, const float);
  PEntity(const float, const float, const t_pos, const float);
  virtual ~PEntity();
  bool			getGod() const;
  void			setGod(const bool);
  void			move(const Map *, const e_dir);
  t_pos			checkVerticalMove(const Map *, const int);
  t_pos			checkHorizontalMove(const Map *, const int);
  virtual void		print();
};

#endif
