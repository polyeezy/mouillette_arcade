//
// GraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/include
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:18:53 2016 Valerian Polizzi
// Last update Thu Mar 17 14:18:31 2016 Valerian Polizzi
//

#ifndef _GRAPHICMANAGER_HH_
# define _GRAPHICMANAGER_HH_

#include <IGraphicManager.hh>

# include <iostream>
# include <dlfcn.h>
# include <string>
# include <map>
# include <stdint.h>
# include <Protocol.hpp>
# include "map.hh"

# define HEIGHT			1080
# define GL_RATIO		0.10
# define GL_SURFACE_WRATIO	0.50
# define GL_SURFACE_HRATIO	0.05
# define GL_TRANS_X		-0.75
# define GL_TRANS_Y		0.75

# include <ControllerManager.hh>

class GraphicManager : public IGraphicManager
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
  IGraphicManager *createGraphicManager();
};

#endif
