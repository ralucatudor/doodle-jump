#include "Score.hpp"

template<typename T>
Score<T>::Score(T score): score(score) 
{
    sf::Font font;
	font.loadFromFile(FONT_FILEPATH);
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Red);
}

template<typename T>
Score<T>::Score(const Score<T>& ob)  
{
    score = ob.score;
    scoreText = ob.scoreText;
}

template<typename T>
T Score<T>::getScore() const
{
    return this->score;
}

template<typename T>
Score<T>& Score<T>::operator=(const Score<T>& other) 
{
    score = other.score;
    updateScoreText();
    return (*this);
}

template<typename T>
Score<T> Score<T>::operator+ (Score<T> const& rhs) 
{ 
    return score + rhs.score;
} 

template<typename T>
void Score<T>::updateScoreText() 
{
    scoreText.setString("Score: " + std::to_string(score));
}

template<typename T>
sf::Text& Score<T>::getScoreText()
{
    return scoreText;
}

template class Score<int>;  
// This will ensure that, when the compiler is compiling Score.cpp 
// that it will explicitly compile all the code for the Score<int>

template class Score<float>;  
