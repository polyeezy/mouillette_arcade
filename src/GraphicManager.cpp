//
// GraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Tue Mar  8 15:01:38 2016 Valerian Polizzi
//

#include <GraphicManager.hh>

GraphicManager::GraphicManager()
{
}

GraphicManager::~GraphicManager()
{
}

void		GraphicManager::createWindow(const std::string &name)
{
  caca_event_t  ev;

  _Window = caca_create_display(NULL);
  caca_set_display_title((caca_display_t*)_Window, name.c_str());
  _Content = caca_get_canvas((caca_display_t*)_Window);
  caca_set_color_ansi((caca_canvas_t*)_Content, CACA_BLACK, CACA_WHITE);
  caca_put_str((caca_canvas_t*)_Content, 35, 1, "Arcade");
}

void		GraphicManager::refresh()
{
  caca_refresh_display((caca_display_t*)_Window);
}

void		GraphicManager::createSurface(const int x, const int y, const int h, const int w, const std::string &name)
{
  _surfaces[name] = caca_get_canvas((caca_display_t*)_Window);
  caca_set_canvas_size((caca_canvas_t*)_surfaces[name], x, y);
}

void		GraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
{
  caca_free_canvas((caca_canvas_t*)_surfaces[surface]);
  this->createSurface(x, y, x, x, surface);
  caca_set_color_ansi((caca_canvas_t*)_surfaces[surface], CACA_RED, CACA_WHITE);
  caca_put_str((caca_canvas_t*)_surfaces[surface], x, y, "                    ");
  this->refresh();
  caca_put_str((caca_canvas_t*)_surfaces[surface], x, y, text.c_str());

}

int		GraphicManager::getKey() const
{
  caca_event_t	ev;
  char		c;

  caca_get_event((caca_display_t*)_Window, CACA_EVENT_KEY_PRESS, &ev, -1);
  c = caca_get_event_key_ch(&ev);
  return (c);
}
