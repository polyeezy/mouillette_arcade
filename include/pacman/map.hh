//
// map.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/include/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 11:35:18 2016 Loïc Weinhard
// Last update Sat Mar 12 09:38:56 2016 Loïc Weinhard
//

#ifndef MAP_HH_
# define MAP_HH_

# include <Protocol.hpp>
# include <vector>
# include <iostream>
# include "Position.hh"

# define MAPS_PATH	"../../games/maps/"

class	Map
{
private:
  std::vector<std::string>	_map;
  t_pos				_door;
  size_t			_gums;
  t_pos				_last_gspawn;

public:
  Map(const std::string &);
  ~Map() {};

public:
  char				getPos(const t_pos) const;
  void				deleteObj(const t_pos);
  void				openCage();
  void				closeCage();
  bool				hasGums();
  t_pos				getPacmanSpawn();
  t_pos				getNextGhostSpawn();
};

#endif
