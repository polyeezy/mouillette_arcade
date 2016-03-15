//
// GraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:18:53 2016 Valerian Polizzi
// Last update Tue Mar 15 19:27:16 2016 Loïc Weinhard
//

#ifndef _GRAPHICMANAGER_HH_
# define _GRAPHICMANAGER_HH_

# include <caca.h>

# include <iostream>
# include <dlfcn.h>
# include <string>
# include <map>
# include <stdint.h>
# include <Protocol.hpp>
# include <SDL/SDL.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include "map.hh"

# define WIDTH			1920
# define HEIGHT			1080
# define GL_RATIO		0.10
# define GL_SURFACE_WRATIO	0.50
# define GL_SURFACE_HRATIO	0.05
# define GL_TRANS_X		-0.75
# define GL_TRANS_Y		0.75

# include <ControllerManager.hh>

class GraphicManager
{
private:
  void		*_Window;
  void		*_Content;
  std::map<const std::string, void *>	_surfaces;
  void		*_handle;
public:
  GraphicManager();
  ~GraphicManager();

  void		setHandle(void *);
  void		createWindow(const std::string &name);
  void		refresh();
  void		print(const Map &);
  void		openLib(const std::string&);
  void		createSurface(const int x, const int y, const int h, const int w, const std::string &name);
  void		addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text);
  void		moveCursorUp();
 int getKey() const;
  void		*getWindow();
  GraphicManager *createGraphicManager();
};

#endif
