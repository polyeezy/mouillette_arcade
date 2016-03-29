//
// sfmlGraphicManager.hh for GraphicManager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/lib/SFML/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Fri Mar 18 10:23:35 2016 Alexis Miele
// Last update Thu Mar 24 12:22:22 2016 Valerian Polizzi
//

#ifndef     SFMLGRAPHICMANAGER_HH_
# define    SFMLGRAPHICMANAGER_HH_

# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>
# include <IGraphicManager.hh>
# include <map>
# include <map.hh>
# include <ControllerManager.hh>

# define WIDTH			1280
# define HEIGHT         720

class sfmlGraphicManager : public IGraphicManager
{
private:
    void    *_Window;
    std::map<const std::string, void *>   _surfaces;
    size_t  _blockSize;
public:
    sfmlGraphicManager();
    ~sfmlGraphicManager();
    void	createWindow(const std::string &);
    void	refresh();
    void    print(const Map &);
    void	createSurface(const int, const int, const int, const int, const std::string &);
    void	addTextToSurface(const std::string &, const int, const int, const std::string&);
    int 	getKey() const;
    void	*getWindow();
  void		printMenu(const std::string &, const std::string &, const std::string &);
};

#endif
