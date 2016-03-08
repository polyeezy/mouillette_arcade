//
// GraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:18:53 2016 Valerian Polizzi
// Last update Tue Mar  8 16:49:53 2016 Valerian Polizzi
//

#ifndef _GRAPHICMANAGER_HH_
# define _GRAPHICMANAGER_HH_

# include <caca.h>

# include <string>
# include <map>

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
  int		getKey() const;
};

#endif
