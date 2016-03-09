//
// ControllerManager.hh for arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Wed Mar  9 10:00:10 2016 Valerian Polizzi
// Last update Wed Mar  9 10:54:37 2016 Valerian Polizzi
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
  enum e_control
    {
      UP = 0,
      DOWN = 1,
      LEFT = 2,
      RIGHT = 3,
      ACTION = 4,
      ESCAPE = 5,
    }	e_control;
  ControllerManager();
  ~ControllerManager();

  void		importConf();
  void		exportConf();
  void		setConfPath(const std::string &);
  void		mapKey(const int key, const int value);
  int		getKey(void *);
};

#endif
