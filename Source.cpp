#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

#define playerNumb 10 //10players in file

void GetBowlingData(char names[][100], int scores[][5], int &n)
{
    //open the file
    ifstream FILE("BowlingScores.txt");

    //Test the file
    if(!FILE.fail())
    {
        //Go through all the file until the end of the file
        while(!FILE.eof())
        {
            FILE>>names[n]>>scores[n][0]>>scores[n][1]>>scores[n][2]>>scores[n][3]>>scores[n][4]; //read the name and the scores of all the players
            n++;
        }
    }
    else
    {
        cout<<"\nError in opening the file"<<endl ;
    }
}

void GetAverageScore(int scores[][5], double average[])
{
    for(int i=0; i<playerNumb; i++)//Calculate the average of EACH player
    {
        average[i] = 0; //Initialise
        for(int j=0; j<5; j++)
        {
            average[i] += scores[i][j];//Sum the scores of 1 player
        }
        average[i] /= 5.0;//Calculate the average of the player
    }
}

void PrettyPrintResults(char names[][100], int scores[][5], double average[], int n)
{//Print the table using a loop for each dimension and respecting the tabulation and line returns
    cout<<left<<setw(15)<<"Name"<<"Score1\tScore2\tScore3\tScore4\tScore5\tAvg_Score"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<left<<setw(15)<<names[i]<<"\t";
        for(int j=0; j<5; j++)
        {
            cout<<scores[i][j]<<"\t";
        }
        cout<<average[i]<<endl;
    }
}

int main()
{
    cout<<"\n***********************\n" ;

    char names[playerNumb][100];//Table of names

    int scores[playerNumb][5];//Table of scores

    double average[playerNumb];//Table of averages

    int n = 0;//n goes from 0 to the number of players, its an index to know what player's score we are printing

    //Call all the functions
    GetBowlingData(names, scores, n) ;
    GetAverageScore(scores, average);
    PrettyPrintResults(names, scores, average, n);

    cout<<"\n***********************\n" ;

    return 0;



}
