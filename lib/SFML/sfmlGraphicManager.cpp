//
// sfmlGraphicManager.cpp for graphicmanager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/lib/SFML/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Fri Mar 18 17:12:45 2016 Alexis Miele
// Last update Mon Mar 21 16:03:51 2016 Alexis Miele
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
    std::cout << "lllleeeeeellll" << std::endl;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), name.c_str());
    _Window = &window;
    //_Window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, 32), name.c_str());
    std::cout << "lllleeeeeellll" << std::endl;
    _blockSize = 0;
    (void)name;
}

void		sfmlGraphicManager::refresh()
{
    //((sf::RenderWindow *)_Window)->Clear(sf::Color::Black);
    /*std::map<const std::string, void *>::iterator p;
    for(p = _surfaces.begin(); p != _surfaces.end(); p++)
        ((sf::RenderWindow *)_Window)->Draw(*((sf::Drawable *)p->second));*/
    //((sf::RenderWindow *)_Window)->Display();
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
    /*sf::Font font;
    if (!font.LoadFromFile("lib/SFML/arial.ttf"))
        exit(EXIT_FAILURE);*/
    //_surfaces[name] = new sf::String("lllleeeeeellll", font);
    /*((sf::String *)_surfaces[name])->setFont(font);
    ((sf::String *)_surfaces[name])->setString("LEEEEEL");
    ((sf::String *)_surfaces[name])->setColor(sf::Color(255,255,255));
    ((sf::String *)_surfaces[name])->setPosition(x, y);
//    ((sf::Text *)_surfaces[name])->setScale(w, h);*/
    //((sf::RenderWindow *)_Window)->draw(*((sf::Text *)_surfaces[name]));
    /*_surfaces[name] = new sf::RectangleShape(sf::Vector2f(w, h));
    ((sf::RectangleShape *)_surfaces[name])->setPosition(x, y);*/
    (void)name;
    (void)h;
    (void)w;
    (void)x;
    (void)y;
}

void		sfmlGraphicManager::addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text)
{
    //((sf::Text *)_surfaces[surface])->setString(text);
    (void)x;
    (void)y;
    (void)text;
    (void)surface;
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
                ((sf::RenderWindow *)_Window)->Close();
                return (ControllerManager::ESCAPE);
                break;

            case sf::Event::KeyPressed :
            {
                switch (event.Key.Code)
                {
                    case sf::Key::Escape :
                        ((sf::RenderWindow *)_Window)->Close();
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

                    default :
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

extern "C" IGraphicManager * createGraphicManager()
{
  return (new sfmlGraphicManager);
}
