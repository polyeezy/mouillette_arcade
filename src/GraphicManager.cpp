//
// GraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Wed Mar  9 10:48:21 2016 Valerian Polizzi
//

#include <GraphicManager.hh>

GraphicManager::GraphicManager()
{
  _focus = 0;
}

GraphicManager::~GraphicManager()
{
}

void		GraphicManager::moveCursorUp()
{
  _focus++;
  if (_focus == 4)
    _focus = 0;
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
  caca_put_str((caca_canvas_t*)_surfaces[surface], x, y, text.c_str());
  this->refresh();

}

void		*GraphicManager::getWindow()
{
  return (_Window);
}

arcade::CommandType		GraphicManager::getKey() const
{
  caca_event_t	ev;
  int		c;

  caca_get_event((caca_display_t*)_Window, CACA_EVENT_KEY_PRESS, &ev, -1);
  c = caca_get_event_key_ch(&ev);
  switch (c)
    {
    case CACA_KEY_UP:
      return (arcade::CommandType::GO_UP);
      break;
    case CACA_KEY_DOWN:
      return (arcade::CommandType::GO_DOWN);
      break;
        case CACA_KEY_LEFT:
      return (arcade::CommandType::GO_LEFT);
      break;
    case CACA_KEY_RIGHT:
      return (arcade::CommandType::GO_RIGHT);
      break;
    default:
      return (arcade::CommandType::GO_UP);
      break;
    }
  return (arcade::CommandType::GO_UP);
}
