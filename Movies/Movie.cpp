#include "Movie.h"

Movie::Movie(const char* name, const char* director, int time, uint8_t genres)
{
	setName(name);
	setDirector(director);
	setTime(time);
	setGenres(genres);
}

Movie::~Movie()
{
	delete[] name;
	delete[] director;
}

Movie& Movie::operator=(const Movie& other)
{
	if (this != &other) { // Check for self-assignment
		
		delete[] name;
		delete[] director;

		
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		director = new char[strlen(other.director) + 1];
		strcpy_s(director, strlen(other.director) + 1, other.director);

		
		time = other.time;
		genres = other.genres;
	}
	return *this;
}

char* Movie::getName() const
{
	return name;
}

void Movie::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name,strlen(name) + 1, name);
}

char* Movie::getDirector() const
{
	return director;
}

void Movie::setDirector(const char* director)
{
	delete[] this->director;
	this->director = new char[strlen(director) + 1];
	strcpy_s(this->director, strlen(director) + 1, director);
}

int Movie::getTime() const
{
	return time;
}

void Movie::setTime(int time)
{
	this->time = time;
}

uint8_t Movie::getGenres() const
{
	return genres;
}

void Movie::setGenres(uint8_t& genres)
{
	this->genres = genres;
}

void Movie::addGenre(const Genres& genre)
{
	genres |= genre;

}

void Movie::removeGenre(const Genres& genre)
{

	genres &= ~genre;
}

bool Movie::checkGenre(const Genres& genre) const
{
	return (genres & genre) == genre;
}

void Movie::toString(std::ostream& os) const
{
	os << "Name: " << name <<
		std::endl << "Director: " << director <<
		std::endl << "Time: " << time << std::endl <<
		"Genres: ";
	if (checkGenre(Genres::Action))
	{
		os << "Genre: Action" << "/";
	}
	if (checkGenre(Genres::Comedy))
	{
		os << "Genre: Comedy" << "/";
	}
	if (checkGenre(Genres::Drama))
	{
		os << "Genre: Drama" << "/";

	}
	if (checkGenre(Genres::Fantasy))
	{
		os << "Genre: Fantasy" << "/";
	}
	if (checkGenre(Genres::Horror))
	{
		os << "Genre: Horror" << "/";
	}
	if (checkGenre(Genres::Mystery))
	{
		os << "Genre: Mystery" << "/";
	}
	if (checkGenre(Genres::Romance)) {
		os << "Genre: Romance" << "/";
	}
	
}



