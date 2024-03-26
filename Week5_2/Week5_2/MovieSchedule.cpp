#include "MovieSchedule.h"

MovieSchedule::MovieSchedule(Movie* movies, int currentSize)
{
	for (size_t i = 0; i < currentSize; i++)
	{
		this->movies[i] = movies[i];
	}
	setSize(currentSize);
	std::cout << "created" << std::endl;
}

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
	if (currentSize < 10)
	{
		movies[currentSize] = movie;
		currentSize++;
	}
	else {
		std::cout << "No space";
	}

}
int MovieSchedule::duration(const Movie& movie)const
{
	int minutes = 0;
	
	for (size_t i = 0; i < currentSize; i++)
	{
		if (strcmp(this->movies[i].getName(), movie.getName()) == 0)
		{
			for (size_t i = 0; i < i-1; i++)
			{
				minutes += this->movies[i].getTime();
			}
			break;
			
		}
	}
	
	
	return minutes;
}
void MovieSchedule::printMovie(const Movie& movie) const
{
	std::cout << movie.getName() << " - " << duration(movie) / 60 << ":" << duration(movie) % 60 << std::endl;
}



int MovieSchedule::allMoviesDuration() const
{
	int minutes = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
		minutes += movies[i].getTime();
	}
	return minutes;
}



