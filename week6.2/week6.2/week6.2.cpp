

#include <iostream>
#include "BelotTournament.h"

int main()
{
	unsigned size = 2;
	SoftwareEngineer s1("Ivan", "Salam", 2);
	SoftwareEngineer s2("Kolbas", "Babalamenko", 500);
	SoftwareEngineer s3("Sarman", "Gogicha", 1000);
	SoftwareEngineer s4("Angel", "Smeshnik", 1);

	SoftwareEngineer team1[] = { s1,s2 };
	SoftwareEngineer team2[] = { s3,s4 };

	Team kesha(team1);
	Team besha(team2);

	Team teams[] = { kesha,besha };

	BelotTournament tournament(teams, 2);
	tournament.tournamentWinner(teams,size);
	std::cout << tournament.gatheredMoney() << std::endl;
}

