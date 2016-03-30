//
// map.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/include/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Tue Mar  8 11:35:18 2016 Loïc Weinhard
// Last update Wed Mar 30 14:36:36 2016 Miele Alexis
//

#ifndef IMAP_HH_
# define IMAP_HH_

# include <Protocol.hpp>
# include <vector>
# include <iostream>
# include "Position.hh"

class	IMap
{
public:
  virtual char				getPos(const t_pos) const = 0;
  virtual void				deleteObj(const t_pos) = 0;
  virtual size_t			getSize() const = 0;
  virtual void				print() = 0;
};

#endif
