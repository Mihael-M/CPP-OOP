#include <iostream>
#include "MovieSchedule.h"


int main()
{
	uint8_t genres = Genres::Action;
	uint8_t genres2 = Genres::Drama;
	Movie movie("Sceletons","Marti",50,genres);
	Movie movie2("Marti the DESTROYER", "Misho", 200, genres2);
	movie2.toString(std::cout);
}

