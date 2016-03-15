//
// GraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:18:53 2016 Valerian Polizzi
// Last update Tue Mar 15 16:02:20 2016 Loïc Weinhard
//

#ifndef _GRAPHICMANAGER_HH_
# define _GRAPHICMANAGER_HH_

# include <caca.h>

# include <string>
# include <map>
# include <stdint.h>
# include <Protocol.hpp>

# define WIDTH		1920
# define HEIGHT		1080
# define GL_RATIO	0.10
# define GL_TRANS_X	-0.75
# define GL_TRANS_Y	0.75

class GraphicManager
{
private:
  void		*_Window;
  void		*_Content;
  std::map<const std::string, void *>	_surfaces;
  size_t	_focus;
  public:
  GraphicManager();
  ~GraphicManager();

  void		createWindow(const std::string &name);
  void		refresh();
  void		createSurface(const int x, const int y, const int h, const int w, const std::string &name);
  void		addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text);
  void		moveCursorUp();
  arcade::CommandType getKey() const;
  void		*getWindow();
};

#endif
