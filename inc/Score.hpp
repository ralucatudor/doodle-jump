#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"

template<typename T>
class Score     // Score Counter class
{
private:
    T score;
public:
    Score(T score = 0);
    Score(const Score<T>& ob);

    T getScore() const;

    // Overload + operator. When incrementing the score - increment the total score with 
    // another ScoreCounter instance having the current obtained score as value.
    // template<typename U>
    Score<T>& operator=(const Score<T>& );
    // template<typename U>
    Score<T> operator + (Score<T> const&);
};
