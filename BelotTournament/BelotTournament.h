#pragma once
#include "Team.h"
constexpr int MIN_SIZE = 3;
class BelotTournament {
private:
	Team* teams = nullptr;
	unsigned currentSize = MIN_SIZE;
	
	void copy(const BelotTournament& other);
	void free();
public:
	BelotTournament() = default;
	BelotTournament(const Team* teams, unsigned currentSize);
	BelotTournament(const BelotTournament& other);
	BelotTournament& operator=(const BelotTournament& other);
	~BelotTournament();
	void setBelotTournament(const Team* teams, unsigned currentSize);
	void tournamentWinner(Team* teams);
	
	void startTournament(Team* teams);
	unsigned gatheredMoney();
	void giveWinner();
	int findWinner();

};
