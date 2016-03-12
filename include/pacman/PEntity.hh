//
// Pacman.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 16:54:19 2016 Loïc Weinhard
// Last update Sat Mar 12 09:54:43 2016 Loïc Weinhard
//

#ifndef PENTITY_HH_
# define PENTITY_HH_

# include <Protocol.hpp>
# include "AEntity.hh"
# include "Position.hh"

class	PEntity : public AEntity
{
private:
  bool			_god;

public:
  PEntity(const float, const float, const float, const float, const float);
  PEntity(const float, const float, const t_pos, const float);
  virtual ~PEntity();
  bool			getGod() const;
  void			setGod(const bool);
  virtual void		print();
};

#endif
