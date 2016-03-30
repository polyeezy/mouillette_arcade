//
// map.hh for map in /home/miele_a/rendu/arcade/mouillette_arcade/include/snake
// 
// Made by Miele Alexis
// Login   <miele_a@epitech.net>
// 
// Started on  Tue Mar 29 15:57:16 2016 Miele Alexis
// Last update Wed Mar 30 15:28:51 2016 Miele Alexis
//

#ifndef SMAP_HH_
# define SMAP_HH_

# include <Protocol.hpp>
# include <vector>
# include <iostream>
# include <IMap.hh>
# include "Position.hh"
# include "SEntity.hh"

# define MAPS_PATH      "../../games/maps/"

class SEntity;

class	SMap: public IMap
{
private:
  std::vector<std::string>	_map;

public:
  SMap(const std::string &);
  ~SMap() {};

public:
  char			getPos(const t_pos) const;
  void			deleteObj(const t_pos);
  size_t		getSize() const;
  void			print();
  t_pos                 getSpawn();
  void			setGum(const SEntity *);
};

#endif
