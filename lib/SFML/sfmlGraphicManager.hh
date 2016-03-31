//
// sfmlGraphicManager.hh for GraphicManager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/lib/SFML/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Fri Mar 18 10:23:35 2016 Alexis Miele
// Last update Wed Mar 30 18:51:32 2016 Loïc Weinhard
//

#ifndef     SFMLGRAPHICMANAGER_HH_
# define    SFMLGRAPHICMANAGER_HH_

# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>
# include <IGraphicManager.hh>
# include <map>
# include <IMap.hh>
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
    void    print(const IMap &);
    void	createSurface(const int, const int, const int, const int, const std::string &);
    void	addTextToSurface(const std::string &, const int, const int, const std::string&);
    int 	getKey() const;
  void		close();
    void	*getWindow();
  void		printMenu(const std::string &, const std::string &, const std::string &);
};

#endif
