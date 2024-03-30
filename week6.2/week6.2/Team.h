#pragma once
#include "SoftwareEngineer.h"

constexpr int TEAM_SIZE = 2;
constexpr int DUEL_WIN = 2;
const int WINNER_POINTS = 151;
class Team {
private:
	SoftwareEngineer softwareEngineers[TEAM_SIZE];
	unsigned points = 0;
	unsigned wins = 0;
	bool isWinnerInDuel = true;
public:
	Team() = default;
	Team(const SoftwareEngineer* softwareEngineers);
	void setTeam(const SoftwareEngineer* softwareEngineers);
	SoftwareEngineer getSE(int index)const;
	void setWinnerInDuel(bool isWinnerInDuel);
	void addPoints(unsigned points);
	bool winRound();
	bool getWinnerInDuel()const ;
	const unsigned getPoints()const;
	void returnPoints();
	
	friend void round(Team& first, Team& second);
	friend void duel(Team& first,Team& second);
};