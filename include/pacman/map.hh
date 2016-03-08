//
// map.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/include/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Tue Mar  8 11:35:18 2016 Loïc Weinhard
// Last update Tue Mar  8 15:32:54 2016 Loïc Weinhard
//

#ifndef MAP_HH_
# define MAP_HH_

# include <Protocol.hpp>
# include <vector>
# include <iostream>

# define MAPS_PATH "../../games/maps/"

class	Map
{
private:
  std::vector<std::string>	_map;
  arcade::Position		_door;
  size_t			_gums;

public:
  Map(const std::string &);
  ~Map() {};

public:
  char				getPos(const arcade::Position) const;
  void				deleteObj(const arcade::Position);
  void				openCage();
  void				closeCage();
  bool				hasGums();
};

#endif
