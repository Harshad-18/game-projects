#include "game.h"
using namespace std;

Game::Game() {

	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";


	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";



}
void Game::Welcome(){
	cout<<" __________________________________________________"<<endl;
	cout<<"|--------------------WELCOME-----------------------|"<<endl;
	cout<<"|__________________________________________________|"<<endl;


	cout<<"\n\n";


	cout<<" __________________________________________________"<<endl;
	cout<<"|_________________Game Instructions________________|"<<endl;
	cout<<"|                                                  |"<<endl;
	cout<<"| 1.Create 2 teams.                                |"<<endl;

	cout<<"|(Team A and Team B each team having 4 players)    |"<<endl;
	cout<<"| 2.Lead the toss and decide choice of play.       |"<<endl;
	cout<<"| 3.Each innings will be 6 balls.                  |"<<endl;

	cout<<"|__________________________________________________|"<<endl;
}

void Game::allplayers(){
	cout<<"____________________________________________________"<<endl;
	cout<<"|                                                  |"<<endl;
	cout<<"|------------------Player Pool---------------------|"<<endl;
	cout<<"|__________________________________________________|"<<endl;
	cout<<"\n";
	for(int i = 0; i < 11; i++){
		cout<<i<<". "<<players[i]<<endl;
	}
}
int Game::takeIntegerInput(){
	int n;

	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"Invalid input please enter valid input: ";
	}
	return n;
}

bool Game::validatePlayer(int index){
	int n;
	vector<Player> players;

	players=teamA.players;
	n=players.size();
	for(int i=0;i<n;i++){
		if(players[i].id==index){
			return false;
		}
	}

	players=teamB.players;
	n=players.size();
	for(int i=0;i<n;i++){
		if(players[i].id==index){
			return false;
		}
	}
	return true;

}


void Game::selectPlayers() {

	cout << endl << "Please select from the given players" << endl;

	cout << "------------------------------------------------" << endl;
	cout << "|========== Create Team-A and Team-B ==========|" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam; i++) {

		// Add player to team A
		teamASelection:
		cout << endl << "Select player " << i + 1 << " of Team A - ";
		int playerIndexTeamA = takeIntegerInput();

		if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
		     cout << endl << "Please select from the given players" << endl;
		     goto teamASelection;

		}else if(!validatePlayer(playerIndexTeamA)){
			cout<<"The player has been already selected.Please select another player."<<endl;
			goto teamASelection;
		}
		else{
			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}

		// Add player to team B
		teamBSelection:
		cout << endl << "Select player " << i + 1 << " of Team B - ";
		int playerIndexTeamB = takeIntegerInput();

		if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
				cout << endl << "Please select from the given players" << endl;
				goto teamBSelection;

		}else if(!validatePlayer(playerIndexTeamB)){
			cout<<"The player has been already selected.Please select another player."<<endl;
			goto teamBSelection;
		}
		else{
		Player teamBPlayer;
		teamBPlayer.name = players[playerIndexTeamB];
		teamB.players.push_back(teamBPlayer);

		}
	}
}

void Game::showTeamPlayers(){
	    vector<Player> teamAPlayers = teamA.players;
	    vector<Player> teamBPlayers = teamB.players;

	    cout << endl << endl;
	    cout << "--------------------------\t\t--------------------------" << endl;
	    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
	    cout << "--------------------------\t\t--------------------------" << endl;

	    for (int i = 0; i < playersPerTeam; i++) {
	        cout<< "|\t" << " " << i << ". " << teamAPlayers[i].name << "\t |"
	        	<< "\t\t"
				<< "|\t" << " " << i << ". " << teamBPlayers[i].name << "\t |" << endl;
	    }
	    cout << "--------------------------\t\t--------------------------" << endl << endl;
	}

void Game::toss(){
	cout<<"tossing the coin............"<<endl;

	srand(time(NULL));
	int randomvalue = rand()%2;

	switch(randomvalue){
	case 0:
		cout << "Team-A won the toss" << endl << endl;
		        tossChoice(teamA);
				break;
	case 1:
		cout << "Team-B won the toss" << endl << endl;
		        tossChoice(teamB);
				break;
	}
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl "<< endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}
void Game::startFirstInnings(){
	cout<<"\n|------------------First Innings Start------------------|"<<endl<<endl;

	isFirstInnings=true;

	initializePlayers();
	playInnings();
	bat();

}


void Game::initializePlayers(){

	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;

}
void Game::playInnings(){

	for (int i = 0; i < maxBalls; i++) {

			cout << "Press Enter to bowl..."<<endl;
			getchar();
			cout << "Bowling..." << endl;

			bat();

		    if (!validateInningsScore()) {
		    	break;
		    }
		}

}
void Game::bat(){
	    srand(time(NULL));
		int runsScored = rand() % 7;

		// Update batting team and batsman score
		batsman->runsScored = batsman->runsScored + runsScored;
		battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
		batsman->ballsPlayed = batsman->ballsPlayed + 1;

		// Update bowling team and bowler score
		bowler->ballsBowled = bowler->ballsBowled + 1;
		bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
		bowler->runsGiven = bowler->runsGiven + runsScored;

	    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
	    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
	    	showGameScoreCard();
	    } else { 	// else runScored = 0 and the batsman is ‘OUT’
	    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

	    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
	    	bowler->wicketsTaken = bowler->wicketsTaken + 1;

	    	showGameScoreCard();

	    	int nextPlayerIndex = battingTeam->wicketsLost;
	    	batsman = &battingTeam->players[nextPlayerIndex];
	    }
	}

bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings

    	validateInningsScore2();
    }

	return true;
}

void Game::showGameScoreCard(){

	cout << "--------------------------------------------------------------------------" << endl;

	    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
	    << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
	    << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
		<< bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

	 cout << "--------------------------------------------------------------------------" << endl << endl;
}
void Game::startSecondInnings(){
	cout<<"\n|------------------Second Innings Start------------------|"<<endl<<endl;

		isFirstInnings=false;

		initializePlayers2();
		playInnings();
		bat2();

}
void Game::initializePlayers2(){
	swap(battingTeam,bowlingTeam);
	swap(batsman,bowler);

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}
void Game::bat2(){
	    srand(time(NULL));
		int runsScored = rand() % 7;

		// Update batting team and batsman score
		batsman->runsScored = batsman->runsScored + runsScored;
		battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
		batsman->ballsPlayed = batsman->ballsPlayed + 1;

		// Update bowling team and bowler score
		bowler->ballsBowled = bowler->ballsBowled + 1;
		bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
		bowler->runsGiven = bowler->runsGiven + runsScored;

		 if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
		    cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
		    showGameScoreCard();

		  } else { 	// else runScored = 0 and the batsman is ‘OUT’
		    cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

		    battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
		    bowler->wicketsTaken = bowler->wicketsTaken + 1;
		    showGameScoreCard();

		    int nextPlayerIndex = battingTeam->wicketsLost;
		    batsman = &battingTeam->players[nextPlayerIndex];
		    }

}
void Game::validateInningsScore2(){


		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

		cout<<"---------------------Game Over-------------------------"<<endl;


	}

}
void Game::result(){

	if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored){
		cout<<"MATCH DRAW"<<endl<<endl;
	}else if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
		cout<<battingTeam->name<<" WON THE MATCH"<<endl<<endl;
	}else{
		cout<<bowlingTeam->name<<" WON THE MATCH"<<endl<<endl;
	}
	cout<<"\t|||MATCH ENDS|||\t"<<endl;
	cout<<"\n\n";
}
void Game::displayResult(){
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];
	//for batting team
	cout<<"\t" << battingTeam->name <<" "<< battingTeam->totalRunsScored <<"-"<<battingTeam->wicketsLost<<"("<<bowlingTeam->totalBallsBowled<<")"<<endl;

	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<"|\tPLAYERS                \tBATTING                \tBOWLING                 |"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;

	for (int i = 0; i < playersPerTeam; i++) {

			if (batsman = &battingTeam->players[i]) {
				summary();
			}
		}


	cout<<"\n\n";
	//for bowling team
	cout<<"\t" << bowlingTeam->name <<" "<< bowlingTeam->totalRunsScored <<"-"<<bowlingTeam->wicketsLost<<"("<<battingTeam->totalBallsBowled<<")"<<endl;

	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<"|\tPLAYERS                \tBATTING                \tBOWLING                 |"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < playersPerTeam; i++) {

			if (bowler = &bowlingTeam->players[i]) {
				summary2();
			}
		}


}

void Game::summary(){
	cout<<"\t"<<batsman->name<<"               \t"<<batsman->runsScored<<"                  \t"<<batsman->ballsBowled << " - " << batsman->runsGiven << " - " << batsman->wicketsTaken<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
}
void Game::summary2(){
	cout<<"\t"<<bowler->name<<"                \t"<<bowler->runsScored<<"                   \t"<<bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
}

