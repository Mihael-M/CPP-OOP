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
	if (this->points >= WINNER_POINTS)
	{
		wins++;
		return true;
	}
	return false;
}

bool Team::getWinnerInDuel() const
{
	return isWinnerInDuel;
}



const unsigned Team::getPoints() const
{
	return points;
}

void round(Team& first, Team& second)
{
	while (first.winRound() || second.winRound())
	{
		unsigned points1;
		std::cout << "Add points-Team 1: ";

		std::cin >> points1;

		first.addPoints(points1);
		unsigned points2;
		std::cout << "Add points-Team 2: ";

		std::cin >> points2;

		second.addPoints(points2);
	}
}

Team duel(Team& first,Team& second)
{
	while (true)
	{
		round(first, second);
		if (first.wins == DUEL_WIN)
		{
			second.isWinnerInDuel = false;
			return first;
		}
			

		else if (second.wins == DUEL_WIN)
		{
			first.isWinnerInDuel = false;
			return second;
		}
			
	}

}
