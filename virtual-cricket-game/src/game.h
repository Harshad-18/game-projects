#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include "team.h" //<vector> "player.h" <string>
class Game{

public:
		Game();

		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;
		void Welcome();
		void allplayers();
		int takeIntegerInput();
		void selectPlayers();
		bool validatePlayer(int);
		void showTeamPlayers();
		void toss();

		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScoreCard();
		void startSecondInnings();
		void initializePlayers2();
		void bat2();
		void validateInningsScore2();
		void result();
		void displayResult();
		void summary();
		void summary2();
};
