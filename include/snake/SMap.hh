//
// map.hh for map in /home/miele_a/rendu/arcade/mouillette_arcade/include/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 15:57:16 2016 Miele Alexis
// Last update Tue Mar 29 18:42:19 2016 Miele Alexis
//

#ifndef SMAP_HH_
# define SMAP_HH_

# include <Protocol.hpp>
# include <vector>
# include <iostream>
# include "Position.hh"
# include "SEntity.hh"

class SEntity;

class	SMap
{
private:
  std::vector<std::string>	_map;

public:
  SMap(const size_t &);
  ~SMap() {};

public:
  char				getPos(const t_pos) const;
  t_pos                         getSpawn();
  void				deleteObj(const t_pos);
  size_t			getSize() const;
  void				print();
  void				setGum(const SEntity *);
};

#endif
