#pragma once
#include "Movie.h"

class MovieSchedule {
private:
	Movie movies[10];
	int currentSize = 0;
	const int MAX_SIZE = 10;
public:
	MovieSchedule() = default;
	MovieSchedule(Movie* movies,int currentSize)
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			this->movies[i] = movies[i];
		}
		this->currentSize = currentSize;
	}
	int getSize()const;
	void setSize(int size);
	void addMovie(const Movie& movie);
	void printMovie(const Movie& movie)const;
	int duration(const Movie& movie)const;
	int allMoviesDuration()const ;
};
