#pragma once
#include <iostream>
#include "Genres.h"

class Movie {
private:
	char* name =new char[1];
	char* director = new char[1];
	int time = 0;
	uint8_t genres;
	
public:
	Movie() = default;
	Movie(const char* name,const char* director,int time,uint8_t genres)
	{

		setName(name);
		setDirector(director);
		setTime(time);
		setGenres(genres);

	}
	~Movie()
	{
		delete[] name;
		delete[] director;
	}
	char* getName() const;
	void setName(const char* name);
	char* getDirector() const;
	void setDirector(const char* director);
	int getTime()const;
	void setTime(int time);
	uint8_t getGenres()const;
	void setGenres(uint8_t& genres);
	void addGenre(Movie& movie, Genres& genre);
	void removeGenre(Movie& movie,Genres& genre);
	bool checkGenre(const Genres& genre)const;
	void toString(std::ostream& os)const;
	
			
			
			
	



};