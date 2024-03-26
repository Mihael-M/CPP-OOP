#include "Movie.h"

char* Movie::getName() const
{
	return name;
}

void Movie::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name,std::strlen(name), name);
}

char* Movie::getDirector() const
{
	return director;
}

void Movie::setDirector(const char* director)
{
	delete[] this->director;
	this->director = new char[strlen(director) + 1];
	strcpy_s(this->director,std::strlen(director), director);
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

void Movie::addGenre(Movie& movie,Genres& genre)
{
	movie.genres |= genre;

}

void Movie::removeGenre(Movie& movie, Genres& genre)
{

	movie.genres &= ~genre;
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
	else {
		os << "No genres.."<<std::endl;
	}
}


