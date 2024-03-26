#include "MovieSchedule.h"

int MovieSchedule::getSize() const
{
	return currentSize;
}

void MovieSchedule::setSize(int size)
{
	this->currentSize = size;
}

void MovieSchedule::addMovie(const Movie& movie)
{
	if (currentSize < MAX_SIZE)
	{
		movies[currentSize] = movie;
		currentSize++;
	}
	else {
		std::cout << "No space";
	}
	
}

void MovieSchedule::printMovie(const Movie& movie) const
{
	std::cout << movie.getName() << " - " << duration(movie) / 60 << ":" << duration(movie) % 60 << std::endl;
}

int MovieSchedule::duration(const Movie& movie) const
{
	int currentIndex = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
		if (strcmp(this->movies[i].getName(),movie.getName())==0)
		{
			currentIndex = i; break;
		}
	}
	int minutes = 0;
	for (size_t i = 0; i < currentIndex-1; i++)
	{
		minutes += this->movies[i].getTime();
	}
	return minutes;
}

int MovieSchedule::allMoviesDuration() const
{
	int minutes = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
		minutes += this->movies[i].getTime();
	}
	return minutes;
}



