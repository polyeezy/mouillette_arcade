//
// game.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
// 
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
// 
// Started on  Wed Mar  9 13:56:17 2016 Loïc Weinhard
// Last update Fri Mar 11 13:00:38 2016 Loïc Weinhard
//

#ifndef PGAME_HH_
# define PGAME_HH_

# include <vector>
# include "PEntity.hh"
# include "map.hh"

# define GHOSTS		6
# define PENTITY_SPEED	0.5
# define PENTITY_WIDTH	30
# define PENTITY_HEIGHT	20

class PGame
{
private:
  Map				*_map;
  PEntity			*_pacman;
  std::vector<PEntity *>	_ghosts;

public:
  PGame(const std::string &);
  ~PGame() {};
};

#endif
