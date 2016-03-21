//
// game.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Wed Mar  9 13:56:17 2016 Loïc Weinhard
// Last update Mon Mar 21 17:02:58 2016 Valerian Polizzi
//

#ifndef PGAME_HH_
# define PGAME_HH_

# include <vector>
# include <IGame.hpp>
# include <ControllerManager.hh>
# include <PEntity.hh>
# include <map.hh>

# define GHOSTS		6
# define PENTITY_SPEED	0.5
# define PENTITY_WIDTH	30
# define PENTITY_HEIGHT	20

class PGame : public IGame
{
private:
  Map				*_map;
  PEntity			*_pacman;
  std::vector<PEntity *>	_ghosts;

public:
  PGame();
  PGame(const std::string &);
  ~PGame() {};
  void		move(const ControllerManager::e_control);
  Map&		getMap() const;
void		play();
};

#endif
