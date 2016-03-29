//
// sfmlGraphicManager.cpp for graphicmanager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/lib/SFML/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Fri Mar 18 17:12:45 2016 Alexis Miele
// Last update Tue Mar 29 13:29:27 2016 Valerian Polizzi
//

#include "sfmlGraphicManager.hh"

sfmlGraphicManager::sfmlGraphicManager()
{
  std::cout << "ok sfml" << std::endl;
}

sfmlGraphicManager::~sfmlGraphicManager()
{
  if (_Window != NULL)
    ((sf::RenderWindow *)_Window)->Close();
}

void		sfmlGraphicManager::createWindow(const std::string &name)
{
    _Window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, 32), name.c_str());
    ((sf::RenderWindow *)_Window)->Clear(sf::Color::Black);
    _blockSize = 0;
}

void		sfmlGraphicManager::refresh()
{
  ((sf::RenderWindow *)_Window)->Clear(sf::Color::Black);
  std::map<const std::string, void *>::iterator p;
  for(p = _surfaces.begin(); p != _surfaces.end(); p++)
    ((sf::RenderWindow *)_Window)->Draw(*((sf::Drawable *)p->second));
  ((sf::RenderWindow *)_Window)->Display();
}

void	sfmlGraphicManager::print(const Map &map)
{
    int     transX;
    int     transY;
    t_pos	pos;

    if (_blockSize == 0)
    {
        if (WIDTH > HEIGHT)
            _blockSize = HEIGHT / map.getSize();
        else
            _blockSize = WIDTH / map.getSize();
    }
    transY = map.getSize() / 2;
    pos.y = 0;
    while (map.getPos(pos) != -1)
    {
      pos.x = 0;
      transX = map.getSize() / 2;
      while (map.getPos(pos) != -2)
        {
            sf::Shape rectangle = sf::Shape::Rectangle(sf::Vector2f((WIDTH / 2) - (transX * _blockSize), (HEIGHT / 2) - (transY * _blockSize)), sf::Vector2f((WIDTH / 2) - (transX * _blockSize) + _blockSize, (HEIGHT / 2) - (transY * _blockSize) + _blockSize), sf::Color(255,255,255));
            //rectangle.setPosition((WIDTH / 2) - (transX * _blockSize), (HEIGHT / 2) - (transY * _blockSize));
            switch (map.getPos(pos))
            {
            case '0':
            case 'G':
            case 'x':
              rectangle.SetColor(sf::Color(255,255,255));
              break;
            case '1':
            case 'P':
              rectangle.SetColor(sf::Color(0,0,255));
              break;
            case '2':
              rectangle.SetColor(sf::Color(255,0,0));
              break;
            }
            ((sf::RenderWindow *)_Window)->Draw(rectangle);
            pos.x += 1;
            transX -= 1;
        }
      pos.y += 1;
      transY -= 1;
    }
    ((sf::RenderWindow *)_Window)->Display();
}

void		sfmlGraphicManager::createSurface(const int x, const int y, const int h, const int w, const std::string &name)
{
    _surfaces[name] = new sf::String;
    ((sf::String *)_surfaces[name])->SetPosition(x, y);
    (void)h;
    (void)w;
}

void		sfmlGraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
{
    ((sf::String *)_surfaces[surface])->SetText(text);
    (void)x;
    (void)y;
}

void		*sfmlGraphicManager::getWindow()
{
  return (_Window);
}

int		sfmlGraphicManager::getKey() const
{
    sf::Event event;

    while (((sf::RenderWindow *)_Window)->GetEvent(event))
    {
        switch (event.Type)
        {
            case sf::Event::Closed :
                return (ControllerManager::ESCAPE);
                break;

            case sf::Event::KeyPressed :
            {
                switch (event.Key.Code)
                {
                    case sf::Key::Escape :
                        return (ControllerManager::ESCAPE);
                        break;

                    case sf::Key::Left :
                        return (ControllerManager::LEFT);
                        break;

                    case sf::Key::Right :
                        return (ControllerManager::RIGHT);
                        break;

                    case sf::Key::Up :
                        return (ControllerManager::UP);
                        break;

                    case sf::Key::Down :
                        return (ControllerManager::DOWN);
                        break;

                    case sf::Key::Space :
                        return (ControllerManager::ACTION);
                        break;

                    // case sf::Key::Back :
                    //     return (8);
                    //     break;

                    default :
		      std::cout << event.Key.Code << std::endl;
                        return (event.Key.Code);
                        break;
                }
            }
            break;

            default :
                break;
        }
    }
    return (0);
}

void	sfmlGraphicManager::printMenu(const std::string &game, const std::string &lib, const std::string &name)
{
  std::cout << game << lib << name << std::endl;
}

extern "C" IGraphicManager * createGraphicManager()
{
  return (new sfmlGraphicManager);
}
