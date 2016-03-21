//
// ControllerManager.hh for arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Wed Mar  9 10:00:10 2016 Valerian Polizzi
// Last update Mon Mar 21 10:50:18 2016 Loïc Weinhard
//

#ifndef _CONTROLLERMANAGER_HH_
# define _CONTROLLERMANAGER_HH_

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>

# define CM_CONF_PATH	"conf/keys.conf"

class ControllerManager
{
private:
  std::map<int, int>	_key_map;
  std::string		_path;
public:
  typedef enum e_control
    {
      UP = 1,
      DOWN = 2,
      LEFT = 3,
      RIGHT = 4,
      ACTION = 5,
      ESCAPE = 6,
    }	e_control;
  ControllerManager();
  ~ControllerManager();

  void		importConf();
  void		exportConf();
  void		setConfPath(const std::string &);
  void		mapKey(const int key, const int value);
  int		getKey(void*);
};

#endif
