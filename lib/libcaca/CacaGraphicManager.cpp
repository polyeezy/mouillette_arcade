//
// GraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Thu Mar 17 17:34:48 2016 Valerian Polizzi
//

#include "CacaGraphicManager.hh"
#include <IGraphicManager.hh>

CacaGraphicManager::CacaGraphicManager()
{

}

 CacaGraphicManager::~CacaGraphicManager()
{
}

void		CacaGraphicManager::createWindow(const std::string &name)
{
  //  caca_event_t  ev;
    (void)name;

    _Window = caca_create_display(NULL);
    caca_set_display_title((caca_display_t*)_Window, name.c_str());
    _Content = caca_get_canvas((caca_display_t*)_Window);
    caca_set_color_ansi((caca_canvas_t*)_Content, CACA_WHITE, CACA_BLACK);
}

void		CacaGraphicManager::refresh()
{
  caca_refresh_display((caca_display_t*)_Window);
}

void		CacaGraphicManager::createSurface(const int x, const int y, const int h, const int w, const std::string &name)
{
  _surfaces[name] = caca_get_canvas((caca_display_t*)_Window);
  caca_set_canvas_size((caca_canvas_t*)_surfaces[name], h, w);
  (void)x;
  (void)y;
}

void		CacaGraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
 {
   //caca_free_canvas((caca_canvas_t*)_surfaces[surface]);
   // this->createSurface(x, y, x, x, surface);
   caca_set_color_ansi((caca_canvas_t*)_surfaces[surface], CACA_BLUE, CACA_BLACK);
   caca_put_str((caca_canvas_t*)_surfaces[surface], x, y, "/***********************\\");
   caca_put_str((caca_canvas_t*)_surfaces[surface], x, y + 1,"|");
   caca_put_str((caca_canvas_t*)_surfaces[surface], x + 24, y + 1,"|");
   caca_put_str((caca_canvas_t*)_surfaces[surface], x, y + 2, "\\***********************/");
   caca_put_str((caca_canvas_t*)_surfaces[surface], x, y + 1, "*************************");
   caca_set_color_ansi((caca_canvas_t*)_surfaces[surface], CACA_WHITE, CACA_BLACK);
   caca_put_str((caca_canvas_t*)_surfaces[surface], x + (text.size() / 2), y + 1, text.c_str());
   //std::cout << text.size() << std::endl;
   //   this->refresh();
}

void		*CacaGraphicManager::getWindow()
{
  return (_Window);
}

int		CacaGraphicManager::getKey() const
{
  caca_event_t	ev;
  int		c;

  caca_get_event((caca_display_t*)_Window, CACA_EVENT_KEY_PRESS, &ev, -1);
  c = caca_get_event_key_ch(&ev);
  switch (c)
    {
    case CACA_KEY_UP:
      return (ControllerManager::UP);
      break;
    case CACA_KEY_DOWN:
      return (ControllerManager::DOWN);
      break;
    case CACA_KEY_LEFT:
      return (ControllerManager::LEFT);
      break;
    case CACA_KEY_RIGHT:
      return (ControllerManager::RIGHT);
      break;
    case CACA_KEY_ESCAPE:
      return (ControllerManager::ESCAPE);
      break;
    default:
      return (c);
      break;
    }
  return (c);
}

extern "C" IGraphicManager * createGraphicManager()
{
  return (new CacaGraphicManager);
}
