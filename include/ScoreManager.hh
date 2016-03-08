//
// ScoreManager.hh for ScoreManager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/include/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Tue Mar  8 15:31:59 2016 Alexis Miele
// Last update Tue Mar  8 23:04:56 2016 Alexis Miele
//

#ifndef                         SCOREMANAGER_HH_
# define                        SCOREMANAGER_HH_

# include                       <vector>
# include                       <string>
# include                       <iostream>
# include                       <sstream>
# include                       <fstream>

class                           ScoreManager {
private:
    std::vector<std::string>    _highscore;
    std::string                 _name;
    std::string                 _path;
    size_t                      _score;
    size_t                      _currentPos;

public:
    ScoreManager(std::string name, std::string path);
    ~ScoreManager();
    void                        setScore(size_t score);
    void                        addScore(size_t score);
    size_t                      getScore(size_t i) const;
    void                        updatePos();
    void                        setName(std::string name);
    std::string                 getName() const;
    void                        importHighscore(std::string path);
    void                        exportHighscore();
    void                        printHighscore() const;
};

#endif
