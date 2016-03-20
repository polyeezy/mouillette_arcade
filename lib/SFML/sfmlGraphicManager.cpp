//
// sfmlGraphicManager.cpp for graphicmanager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/lib/SFML/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Fri Mar 18 17:12:45 2016 Alexis Miele
// Last update Sun Mar 20 02:27:59 2016 Alexis Miele
//

#include "sfmlGraphicManager.hh"

sfmlGraphicManager::sfmlGraphicManager()
{
  std::cout << "ok sfml" << std::endl;
}

sfmlGraphicManager::~sfmlGraphicManager()
{

}

void		sfmlGraphicManager::createWindow(const std::string &name)
{
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), name.c_str());
  window.clear(sf::Color::Black);
  _Window = &window;
  _blockSize = 0;
}

void		sfmlGraphicManager::refresh()
{
  return;
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
            sf::RectangleShape rectangle(sf::Vector2f(_blockSize, _blockSize));
            rectangle.setPosition((WIDTH / 2) - (transX * _blockSize), (HEIGHT / 2) - (transY * _blockSize));
            switch (map.getPos(pos))
            {
            case '0':
            case 'G':
            case 'x':
              rectangle.setFillColor(sf::Color(255,255,255));
              break;
            case '1':
            case 'P':
              rectangle.setFillColor(sf::Color(0,0,255));
              break;
            case '2':
              rectangle.setFillColor(sf::Color(255,0,0));
              break;
            }
            ((sf::RenderWindow *)_Window)->draw(rectangle);
            pos.x += 1;
            transX -= 1;
        }
      pos.y += 1;
      transY -= 1;
    }
    ((sf::RenderWindow *)_Window)->display();
}

void		sfmlGraphicManager::createSurface(const int x, const int y, const int h, const int w, const std::string &name)
{
    sf::Text text;
    text.setPosition(x, y);
    text.setScale(w, h);
    _surfaces[name] = &text;
}

void		sfmlGraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
{
  ((sf::Text *)_surfaces[surface])->setString(text);
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

    while (((sf::RenderWindow *)_Window)->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            return (ControllerManager::ESCAPE);
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                return (ControllerManager::LEFT);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                return (ControllerManager::RIGHT);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                return (ControllerManager::UP);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                return (ControllerManager::DOWN);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                return (ControllerManager::ESCAPE);
            else
                return (event.key.code);
        }
    }
    return (0);
}

extern "C" IGraphicManager * createGraphicManager()
{
  return (new sfmlGraphicManager);
}
