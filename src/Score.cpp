#include "Score.hpp"

template<typename T>
Score<T>::Score(T score): score(score) {}

template<typename T>
Score<T>::Score(const Score<T>& ob)     // copy constructor
{
    score = ob.score;
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
    return (*this);
}

template<typename T>
Score<T> Score<T>::operator+ (Score<T> const& ob) 
{ 
    Score newScore;
    newScore.score = this->score + ob.score;
    return newScore;
} 

template class Score<int>;  
// This will ensure that, when the compiler is compiling Score.cpp 
// that it will explicitly compile all the code for the Score<int>

template class Score<float>;  
