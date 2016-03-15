//
// ScoreManager.cpp for ScoreManager in /home/alexismiele/rendu/Semestre_4/Arcade/mouillette_arcade/src/
//
// Made by Alexis Miele
// Login   <miele_a@epitech.eu>
//
// Started on  Tue Mar  8 15:48:16 2016 Alexis Miele
// Last update Thu Mar 10 14:07:02 2016 Alexis Miele
//

#include "ScoreManager.hh"

ScoreManager::ScoreManager(const std::string &name, const std::string &path)
{
    _name = name;
    _score = 0;
    _path = path;
    if (!_path.empty())
    {
        this->importHighscore();
        if (_highscore.size() < HIGHSCORE_SIZE)
            {
                _currentPos = _highscore.size();
                std::stringstream ss;
                ss << _score;
                _highscore.push_back(name + ":" + ss.str());
            }
        else
            _currentPos = HIGHSCORE_SIZE;
    }
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::setScore(const size_t &score)
{
    _score = score;
    this->updatePos();
}

void ScoreManager::addScore(const size_t &score)
{
    _score += score;
    this->updatePos();
}

size_t ScoreManager::getScore(const size_t &i) const
{
    size_t tmp;

    if (i >= HIGHSCORE_SIZE)
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
    if (i < HIGHSCORE_SIZE)
    {
        if (_currentPos < HIGHSCORE_SIZE)
            _highscore.erase(_highscore.begin() + _currentPos);
        _currentPos = i;
        std::stringstream ss;
        ss << _score;
        _highscore.insert(_highscore.begin() + i, _name + ":" + ss.str());
        while (_highscore.size() > HIGHSCORE_SIZE)
            _highscore.erase(_highscore.begin() + HIGHSCORE_SIZE);
    }
}

void ScoreManager::setName(const std::string &name)
{
    _name = name;
}

const std::string &ScoreManager::getName() const
{
    return _name;
}

void ScoreManager::setPath(const std::string &path)
{
    _path = path;
}

const std::string &ScoreManager::getPath() const
{
    return _path;
}

void ScoreManager::importHighscore()
{
    if (!_path.empty())
    {
        std::ifstream file;
        file.open(_path.c_str(), std::ifstream::in);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
                _highscore.push_back(line);
            file.close();
        }
        while (_highscore.size() > HIGHSCORE_SIZE)
            _highscore.erase(_highscore.begin() + HIGHSCORE_SIZE);
    }
}

void ScoreManager::exportHighscore() const
{
    if (!_path.empty())
    {
        std::ofstream file;
        file.open(_path.c_str(), std::ofstream::out | std::ofstream::trunc);
        if (file.is_open())
        {
            for (size_t i = 0; i < _highscore.size(); i++)
            {
                file << _highscore[i] << "\n";
            }
            file.close();
        }
    }
}

void ScoreManager::printHighscore() const
{
    std::cout << "--- SCORE : ---" << std::endl;
    for (size_t i = 0; i < _highscore.size(); i++)
        std::cout << "\t" << _highscore[i].substr(0, _highscore[i].find(":")) << "\t" << _highscore[i].substr(_highscore[i].find(":")) << std::endl;
}
