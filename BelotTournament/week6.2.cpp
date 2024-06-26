

#include <iostream>
#include "BelotTournament.h"

int main()
{
	unsigned size = 2;
	SoftwareEngineer s1("Ivan", "UG", 2);
	SoftwareEngineer s2("Eugenia", "MP", 500);
	SoftwareEngineer s3("Sloeman", "Gogicha", 1000);
	SoftwareEngineer s4("Patias", "Smeshnik", 1);

	SoftwareEngineer team1[] = { s1,s2 };
	SoftwareEngineer team2[] = { s3,s4 };

	Team kesha(team1);
	Team besha(team2);

	Team teams[] = { kesha,besha };
	
	BelotTournament tournament(teams, 2);
	
	tournament.tournamentWinner(teams);
	
	std::cout << std::endl;
	std::cout << kesha.getWinnerInDuel() << std::endl;
	std::cout << besha.getWinnerInDuel()<<std::endl;
	//std::cout << tournament.findWinner();
}

