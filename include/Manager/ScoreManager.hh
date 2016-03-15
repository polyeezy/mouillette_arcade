//
// ScoreManager.hh for ScoreManager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/include/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Tue Mar  8 15:31:59 2016 Alexis Miele
// Last update Thu Mar 10 14:07:10 2016 Alexis Miele
//

#ifndef                         SCOREMANAGER_HH_
# define                        SCOREMANAGER_HH_

# include                       <vector>
# include                       <string>
# include                       <iostream>
# include                       <sstream>
# include                       <fstream>

# define                        HIGHSCORE_SIZE 10

class                           ScoreManager {
private:
    std::vector<std::string>    _highscore;
    std::string                 _name;
    std::string                 _path;
    size_t                      _score;
    size_t                      _currentPos;

public:
    ScoreManager(const std::string &name = "", const std::string &path = "");
    ~ScoreManager();
    void                        setScore(const size_t &score);
    void                        addScore(const size_t &score);
    size_t                getScore(const size_t &i) const;
    void                        updatePos();
    void                        setName(const std::string &name);
    const std::string           &getName() const;
    void                        setPath(const std::string &path);
    const std::string           &getPath() const;
    void                        importHighscore();
    void                        exportHighscore() const;
    void                        printHighscore() const;
};

#endif
