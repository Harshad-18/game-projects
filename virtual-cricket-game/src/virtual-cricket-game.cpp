#include "game.h"
using namespace std;

int main() {

	Game game;
	game.Welcome();

	cout<<"\n";

	cout<<"Press Enter to continue.....";
	cin.get();

	game.allplayers();

	cout<<"\n";

	cout<<"Press Enter to continue.....";
	cin.get();

	game.selectPlayers();

	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout<<"Press Enter to toss"<<endl;;
	cin.get();

	game.toss();

	game.startFirstInnings();

	game.startSecondInnings();

	game.result();

	game.displayResult();


	return 0;
}
