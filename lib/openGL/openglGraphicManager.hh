//
// openglGraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/lib/openGL
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Thu Mar 17 14:15:36 2016 Valerian Polizzi
// Last update Thu Mar 31 16:45:54 2016 Loïc Weinhard
//

#ifndef _OPENGLGRAPHICMANAGER_HH_
# define _OPENGLGRAPHICMANAGER_HH_

# include <IGraphicManager.hh>
# include <SDL/SDL.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include <IMap.hh>
# include <ControllerManager.hh>

# define WIDTH			1280
# define HEIGHT                 720
# define GL_RATIO               0.05
# define GL_SURFACE_WRATIO      0.50
# define GL_SURFACE_HRATIO      0.05
# define GL_TRANS_X             -0.75
# define GL_TRANS_Y             0.75

class openglGraphicManager : public IGraphicManager
{
private:
void          *_Window;
void          *_Content;
std::map<const std::string, void *>   _surfaces;
void          *_handle;
public:
openglGraphicManager();
~openglGraphicManager();
void          setHandle(void *);
void          createWindow(const std::string &name);
void          refresh();
void          print(const IMap &);
void          openLib(const std::string&);
void          createSurface(const int x, const int y, const int h, const int w, const std::string &name);
void          addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text);
void          moveCursorUp();
  void		close();
int	      getKey() const;
void          *getWindow();
  void		printMenu(const std::string&, const std::string &, const std::string&);
IGraphicManager *createGraphicManager();
};

#endif
