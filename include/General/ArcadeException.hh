//
// ArcadeException.hh for  in /home/polizz_v/rendu/cPP/mouillette_arcade/src/General
// 
// Made by Valerian Polizzi
// Login   <polizz_v@epitech.net>
// 
// Started on  Fri Apr  1 10:36:52 2016 Valerian Polizzi
// Last update Fri Apr  1 17:33:48 2016 Miele Alexis
//

#ifndef _ARCADEEXCEPTION_HH_
# define _ARCADEEXCEPTION_HH_

# include <exception>
# include <string>

namespace arcade
{
  class Exception : public std::exception
  {
  private:
    std::string _msg;
  public:
    Exception(const std::string &);
    virtual ~Exception() throw (){}
    virtual const char *what () const throw()
    {
      return (_msg.c_str());
    }
  };
}

#endif
