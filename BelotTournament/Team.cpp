#include "Team.h"

Team::Team(const SoftwareEngineer* softwareEngineers)
{
	setTeam(softwareEngineers);
}

void Team::setTeam(const SoftwareEngineer* softwareEngineers)
{
	for (size_t i = 0; i < TEAM_SIZE; i++)
	{
		this->softwareEngineers[i] = softwareEngineers[i];
	}

}

SoftwareEngineer Team::getSE(int index) const
{
	return this->softwareEngineers[index];
}

void Team::setWinnerInDuel(bool isWinnerInDuel)
{
	this->isWinnerInDuel = isWinnerInDuel;
}

void Team::addPoints(unsigned points)
{
	this->points += points;
}
bool Team::winRound() {

	return this->points >= WINNER_POINTS;
}

bool Team::getWinnerInDuel() const
{
	return isWinnerInDuel;
}



const unsigned Team::getPoints() const
{
	return points;
}

void Team::returnPoints()
{
	points = 0;
}

void round(Team& first, Team& second)
{
	while (true)
	{

		unsigned points1;
		std::cout << "Add points-Team 1: ";
		std::cin >> points1;
		first.addPoints(points1);
		std::cout << "Team 1 - points: " << first.getPoints() << std::endl;




		unsigned points2;
		std::cout << "Add points-Team 2: ";
		std::cin >> points2;
		second.addPoints(points2);
		std::cout << "Team 2 - points: " << first.getPoints() << std::endl;
		if (first.winRound())
		{
			first.wins++;
			first.returnPoints();
			second.returnPoints();
			std::cout << "Team 1 Won " << std::endl;
			return;
		}

		else if (second.winRound())
		{
			second.wins++;
			first.returnPoints();
			second.returnPoints();
			std::cout << "Team 2 Won " << std::endl;
			return;
		}

	}
}

void duel(Team& first, Team& second)
{
	unsigned roundCounter = 1;
	while (true)
	{
		std::cout << "Round: " << roundCounter << std::endl;
		std::cout << std::endl;

		round(first, second);
		std::cout << std::endl;
		std::cout << "Team 1 wins: " << first.wins << std::endl;
		std::cout << std::endl;
		std::cout << "Team 2 wins: " << second.wins << std::endl;
		std::cout << std::endl;
		roundCounter++;
		if (first.wins == DUEL_WIN)
		{

			second.isWinnerInDuel = false;
			std::cout << "Team 1 Won the Duel" << std::endl;
			return;
		}


		else if (second.wins == DUEL_WIN)
		{

			first.isWinnerInDuel = false;
			std::cout << "Team 2 Won the Duel" << std::endl;
			return;
		}

	};
}



