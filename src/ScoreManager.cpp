//
// ScoreManager.cpp for ScoreManager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/src/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Tue Mar  8 15:48:16 2016 Alexis Miele
// Last update Tue Mar  8 23:10:09 2016 Alexis Miele
//

#include "ScoreManager.hh"

ScoreManager::ScoreManager(std::string name, std::string path)
{
    _name = name;
    _score = 0;
    _path = path;
    this->importHighscore(path);
    if (_highscore.size() < 10)
        {
            _currentPos = _highscore.size();
            std::stringstream ss;
            ss << _score;
            _highscore.push_back(name + ":" + ss.str());
        }
    else
        _currentPos = 10;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::setScore(size_t score)
{
    _score = score;
    this->updatePos();
}

void ScoreManager::addScore(size_t score)
{
    _score += score;
    this->updatePos();
}

size_t ScoreManager::getScore(size_t i) const
{
    size_t tmp;

    if (i > 9)
        return 0;
    std::stringstream sstream(_highscore[i].substr(_highscore[i].find(":") + 1));
    sstream >> tmp;
    return tmp;
}

void ScoreManager::updatePos()
{
    size_t i;

    i = _currentPos;
    while (i > 0 && _score > this->getScore(i - 1))
        i--;
    if (i < 10)
    {
        if (_currentPos < 10)
            _highscore.erase(_highscore.begin() + _currentPos);
        _currentPos = i;
        std::stringstream ss;
        ss << _score;
        _highscore.insert(_highscore.begin() + i, _name + ":" + ss.str());
        while (_highscore.size() > 10)
            _highscore.erase(_highscore.begin() + 10);
    }
}

void ScoreManager::setName(std::string name)
{
    _name = name;
}

std::string ScoreManager::getName() const
{
    return _name;
}

void ScoreManager::importHighscore(std::string path)
{
    std::ifstream file;
    file.open(path.c_str(), std::ifstream::in);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
            _highscore.push_back(line);
        file.close();
    }
    while (_highscore.size() > 10)
        _highscore.erase(_highscore.begin() + 10);
}

void ScoreManager::exportHighscore()
{
    std::ofstream file;
    file.open(_path.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (file.is_open())
    {
        for (int i = 0; i < _highscore.size(); i++)
        {
            file << _highscore[i] << "\n";
        }
        file.close();
    }
}

void ScoreManager::printHighscore() const
{
    std::cout << "--- SCORE : ---" << std::endl;
    for (int i = 0; i < _highscore.size(); i++)
    {
        std::cout << "\t" << _highscore[i].substr(0, _highscore[i].find(":")) << "\t" << _highscore[i].substr(_highscore[i].find(":")) << std::endl;
    }
}
