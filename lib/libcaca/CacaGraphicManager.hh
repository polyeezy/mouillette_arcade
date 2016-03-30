//
// CacaGraphicManager.hh for  in /home/polyeezy/rendu/CPP/mouillette_arcade/lib/libcaca
//
// Made by Valerian Polizzi
// Login   <polyeezy@epitech.net>
//
// Started on  Wed Mar 16 15:13:24 2016 Valerian Polizzi
// Last update Wed Mar 30 15:01:44 2016 Miele Alexis
//

#ifndef _CACAGRAPHICMANAGER_HH_
# define _CACAGRAPHICMANAGER_HH_

# include <IGraphicManager.hh>
# include <caca.h>
# include <map>
# include <IMap.hh>
# include <ControllerManager.hh>

class CacaGraphicManager : public IGraphicManager
{
private:
  void          *_Window;
  void          *_Content;
  std::map<const std::string, void *>   _surfaces;
  void          *_handle;
public:
  CacaGraphicManager();
  ~CacaGraphicManager();
  void          setHandle(void *);
  void          createWindow(const std::string &name);
  void          refresh();
  void		close();
  void		printMenu(const std::string &lib, const std::string &game, const std::string &name);
  void          print(const IMap &);
  void          openLib(const std::string&);
  void          createSurface(const int x, const int y, const int h, const int w, const std::string &name);
  void          addTextToSurface(const std::string &surface, const int x, const int y, const std::string &text);
  void          moveCursorUp();
  int getKey() const;
  void          *getWindow();
  IGraphicManager *createGraphicManager();
};

#endif
