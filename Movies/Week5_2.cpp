#include <iostream>
#include "MovieSchedule.h"


int main()
{
	uint8_t genres = Genres::Action;
	uint8_t genres2 = Genres::Drama;
	Movie movie("Sceletons", "Marti", 50, genres);
	Movie movie2("Marti the DESTROYER", "Misho", 200, genres2);
	Movie movies[2];
	movies[0] = movie;
	movies[1] = movie2;
	MovieSchedule mv(movies, 2);
	mv.printMovie(movie);
	std::cout << std::endl;
	std::cout<<mv.allMoviesDuration();
	std::cout<<std::endl;
	movie.toString(std::cout);
	std::cout << std::endl;
	movie2.toString(std::cout);
	
}

