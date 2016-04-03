//
// GraphicManager.cpp for Arcade in /home/polyeezy/rendu/CPP/mouillette_arcade/src
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Tue Mar  8 11:25:41 2016 Valerian Polizzi
// Last update Sun Apr  3 13:55:16 2016 Valerian Polizzi
//

#include "CacaGraphicManager.hh"
#include <IGraphicManager.hh>

CacaGraphicManager::CacaGraphicManager()
{

}

 CacaGraphicManager::~CacaGraphicManager()
{
  //  caca_free_display((caca_display_t*)_Window);
}

void		CacaGraphicManager::print(const IMap &map)
{
  t_pos		pos;

  _surfaces["Arcade"] = caca_get_canvas((caca_display_t*)_Window);
  pos.y = 0;
  while (map.getPos(pos) != -1)
    {
      pos.x = 0;
      while (map.getPos(pos) != -2)
	{
	  switch (map.getPos(pos))
	    {
	    case '0':
	      caca_set_color_ansi((caca_canvas_t*)_surfaces["Arcade"], CACA_GREEN, CACA_BLACK);
	      this->addTextToSurface("Arcade", pos.x, pos.y, "*");
	      break;
	    case 'G':
	    case 'x':
	      caca_set_color_ansi((caca_canvas_t*)_surfaces["Arcade"], CACA_BLACK, CACA_BLACK);
	      this->addTextToSurface("Arcade", pos.x, pos.y, "*");
	      break;
	    case '1':
	    case 'P':
	      caca_set_color_ansi((caca_canvas_t*)_surfaces["Arcade"], CACA_BLUE, CACA_BLACK);
	      this->addTextToSurface("Arcade", pos.x, pos.y, "X");
	      break;
	    case '2':
	      caca_set_color_ansi((caca_canvas_t*)_surfaces["Arcade"], CACA_RED, CACA_BLACK);
	      this->addTextToSurface("Arcade", pos.x, pos.y, "!");
	      break;
	    case '#':
	      caca_set_color_ansi((caca_canvas_t*)_surfaces["Arcade"], CACA_YELLOW, CACA_BLACK);
	      this->addTextToSurface("Arcade", pos.x, pos.y, "P");
	      break;
	    }
	  this->refresh();
	  pos.x++;
	}
      pos.y++;
    }
}
void		CacaGraphicManager::close()
{
  caca_free_display((caca_display_t*)_Window);
}

void		CacaGraphicManager::printMenu(const std::string &game, const std::string &lib, const std::string &name)
{
  std::cout << lib << name << std::endl;

  _surfaces["Games"] = caca_get_canvas((caca_display_t*)_Window);
  _surfaces["Libs"] = caca_get_canvas((caca_display_t*)_Window);
  _surfaces["Name"] = caca_get_canvas((caca_display_t*)_Window);

  caca_set_color_ansi((caca_canvas_t*)_surfaces["Games"], CACA_BLUE, CACA_BLACK);

  this->addTextToSurface("Games", 30, 5, game);
  this->addTextToSurface("Libs", 30, 10, lib);
  this->addTextToSurface("Name", 30, 15, name);

  this->refresh();
}

void		CacaGraphicManager::createWindow(const std::string &name)
{
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
   //   caca_set_color_ansi((caca_canvas_t*)_surfaces[surface], CACA_BLUE, CACA_BLACK);
   caca_put_str((caca_canvas_t*)_surfaces[surface], x +  20 + (text.size() / 2), y + 1, text.c_str());
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

  caca_get_event((caca_display_t*)_Window, CACA_EVENT_KEY_PRESS, &ev, 0);
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
    case CACA_KEY_RETURN:
      return (ControllerManager::ACTION);
      break;
    default:
      return (0);
      break;
    }
  return (c);
}

void	CacaGraphicManager::setTexture(const char &c, const std::string &path)
{
  (void)c;
  (void)path;
}

extern "C" IGraphicManager * createGraphicManager()
{
  return (new CacaGraphicManager);
}
