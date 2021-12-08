// Week06.cpp : program to calculate a bowling league's average bowling scores and reads the input data from the file BowlingScores.txt



#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Declaring variables
const int N_players = 10;
const int N_games = 5;

// Function prototypes
// get data from file
int GetBowlingData(char filename[], string names[], int scores[][N_games]); 
// calculate averages for each player
void GetAverageScore(int scores[][N_games], double avg[]); 
// Display results
void PrettyPrintResults(string names[], int scores[][N_games], double avg[]); 



// Display results
void PrettyPrintResults(string names[], int scores[][N_games], double avg[])
{
	cout << "\n" << endl;
	cout << setw(42) << setfill('~') << "" << endl;
	cout << setw(30) << setfill('>') << " Bowling Scores " << setw(12) << setfill('<') << "" << endl; 
	cout << setw(42) << setfill('~') << "" << endl; 
	cout << "\n" << endl;


	cout << "\n" << endl;
	// Prints each player name, scores and average 
	for (int player = 0; player < N_players; player++)
	{
		cout << names[player] << "'s scores are: ";;

		for (int cols = 0; cols < (N_games); cols++)
		{
			cout << scores[player][cols] << " ";
		}


		cout  << "  with Avarage of : " << avg[player] <<endl;
	}
}

int GetBowlingData(char filename[], string names[], int scores[][N_games])
{
	ifstream inData;
	inData.open(filename);

	if (!inData) //checks to see if file opens if not is an error
	{
		cout << "There is an error\n";
		return -1;
	}

	// for loop to get data for the rows
	for (int rows = 0; rows < N_players; rows++)
	{
		//for loop to get data for scores
		inData >> names[rows];

		for (int cols = 0; cols < N_games; cols++)
		{
			inData >> scores[rows][cols];
		}
	}


	inData.close();
	return 0;
}
//function to get the average score for each player
void GetAverageScore(int scores[][N_games], double avg[])
{
	double sum = 0;

	for (int bowlers = 0; bowlers < N_players; bowlers++)
	{
		// find the scores for each player
		for (int games = 0; games < N_games; games++)
		{
			sum += scores[bowlers][games];
		}
	// calculate average
		avg[bowlers] = sum / N_games;
		sum = 0;
	}
}

int main()
{
	// Arrays and variables
	string player_names[N_players];
	int game_scores[N_players][N_games];
	double avg_scores[N_players];
	char file_name[] = "BowlingScores.txt";

	// Function calls
	GetBowlingData(file_name, player_names, game_scores);
	GetAverageScore(game_scores, avg_scores);
	PrettyPrintResults(player_names, game_scores, avg_scores);
}
