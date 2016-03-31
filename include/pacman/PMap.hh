//
// map.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/include/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Tue Mar  8 11:35:18 2016 Loïc Weinhard
// Last update Wed Mar 30 15:12:46 2016 Miele Alexis
//

#ifndef PMAP_HH_
# define PMAP_HH_

# include <Protocol.hpp>
# include <vector>
# include <iostream>
# include <IMap.hh>
# include "Position.hh"

# define MAPS_PATH	"../../games/maps/"

class	PMap: public IMap
{
private:
  std::vector<std::string>	_map;
  t_pos				_door;
  size_t			_gums;
  t_pos				_last_gspawn;

public:
  PMap(const std::string &);
  ~PMap() {};

public:
  char			getPos(const t_pos) const;
  void			deleteObj(const t_pos);
  void			openCage();
  void			closeCage();
  bool			hasGums();
  t_pos			getPacmanSpawn();
  t_pos			getNextGhostSpawn();
  size_t		getSize() const;
  void			print();
};

#endif
