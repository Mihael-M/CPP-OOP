#include "BelotTournament.h"
#include <iostream>

void BelotTournament::copy(const BelotTournament& other)
{
	this->teams = new Team[other.currentSize];
	for (size_t i = 0; i < other.currentSize; i++)
	{
		this->teams[i] = other.teams[i];
	}
	this->currentSize = other.currentSize;
}

void BelotTournament::free()
{
	delete[] teams;
}

BelotTournament::BelotTournament(const Team* teams, unsigned currentSize)
{
	setBelotTournament(teams, currentSize);
}

BelotTournament::BelotTournament(const BelotTournament& other)
{
	copy(other);
}

BelotTournament& BelotTournament::operator=(const BelotTournament& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

BelotTournament::~BelotTournament()
{
	free();
}

void BelotTournament::setBelotTournament(const Team* teams, unsigned currentSize)
{
	if (!teams || this->teams == teams)
	{
		
		std::cout << "error";
		return;
	}
	if (currentSize % 2 != 0)
	{
		currentSize--;
	}
	this->teams = new Team[currentSize];
	for (size_t i = 0; i < currentSize; i++)
	{
		this->teams[i] = teams[i];
	}
	this->currentSize = currentSize;
}

void BelotTournament::tournamentWinner(Team* teams)
{
	
	int count = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
		count++;
		if (teams[i].getWinnerInDuel())
		{
			
			for (size_t j = i + 1; j < currentSize; j++)
			{
				if (teams[j].getWinnerInDuel()) {

					duel(teams[i], teams[j]);
					i++;
					break;
				}
			}
		}
	}
	
	
	if (count == currentSize - 1);
	return;
	
	
	this->tournamentWinner(teams);	
}

void BelotTournament::startTournament(Team* teams) 
{
	std::srand(std::time(nullptr));
	for (unsigned i = 0; i < currentSize; ++i) {
		unsigned j = std::rand() % currentSize;
		std::swap(teams[i], teams[j]);
	}
	
	tournamentWinner(teams);
	
	std::cout << "Total donation collected: $ " << gatheredMoney() << std::endl;
}


unsigned BelotTournament::gatheredMoney()
{
	unsigned gathered = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
		unsigned toGive = 0;

		if (!teams[i].getWinnerInDuel()) {

			for (size_t j = 0; j < TEAM_SIZE; j++)
			{
				toGive = (teams[i].getSE(j).getSalary());
				gathered += toGive * 0.02;
			}
		}
	
	
		
	}
	return gathered;
}

void BelotTournament::giveWinner()
{
	unsigned earned = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
		unsigned toGive = 0;

		if (!teams[i].getWinnerInDuel()) {

			for (size_t j = 0; j < TEAM_SIZE; j++)
			{
				toGive = (teams[i].getSE(j).getSalary());
				earned += toGive * 0.01;
			}
		}



	}
	for (size_t i = 0; i < TEAM_SIZE; i++)
	{
		int sumToChange =earned + teams[findWinner()].getSE(i).getSalary();
		teams[findWinner()].getSE(i).setSalary(sumToChange);
	}

}

int BelotTournament::findWinner()
{
	for (int i = 0; i < currentSize; i++)
	{

		if (teams[i].getWinnerInDuel()) {

			return i;
		}
	}
}

