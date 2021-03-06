//
// game.hh for  in /home/weinha_l/Semestre_4/mouillette_arcade/src/pacman
//
// Made by Loïc Weinhard
// Login   <weinha_l@epitech.net>
//
// Started on  Wed Mar  9 13:56:17 2016 Loïc Weinhard
// Last update Sun Apr  3 11:53:10 2016 Valerian Polizzi
//

#ifndef PGAME_HH_
# define PGAME_HH_

# include <vector>
# include <IGame.hpp>
# include <ControllerManager.hh>
# include <IGraphicManager.hh>
# include <PEntity.hh>
# include <PMap.hh>

# define GHOSTS		6
# define PENTITY_SPEED	0.5
# define PENTITY_WIDTH	30
# define PENTITY_HEIGHT	20
# define PACMAN_PATH ("./src/pacman/")

class PGame : public IGame
{
private:
  PMap				*_map;
  PEntity			*_pacman;
  std::vector<PEntity *>	_ghosts;
  IGraphicManager		*_gm;
public:
  PGame();
  PGame(const std::string &);
  ~PGame() {};
  void		setMap(const std::string&);
  void		setGM(IGraphicManager *);
  IGraphicManager *getGM();
  void		move(const int);
  PMap&		getMap() const;
  void		play();
  PEntity&	getPacman() const;
};



#endif
