#include "Score.hpp"

Score::Score(int score): score(score) {}

int Score::getScore() const
{
    return this->score;
}

Score& Score::operator=(const Score& other) 
{
    score = other.score;
    return (*this);
}

Score Score::operator+ (Score const& rhs) 
{ 
    return score + rhs.score;
} 