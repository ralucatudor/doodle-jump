#pragma once

// add template
class Score     // Score Counter class
{
private:
    int score;
public:
    Score(int score = 0);

    int getScore() const;

    // Overload + operator. When incrementing the score - increment the total score with 
    // another ScoreCounter instance having the current obtained score as value.

    Score& operator=(const Score& );
    Score operator + (Score const&);
};