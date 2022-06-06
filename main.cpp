#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include"Player.h"
using namespace std;

void playFunction1(Player&, int);
void playFunction2(Player& p1, Player& p2);
void whoWin(Player& p1, Player& p2);
void play1();
void play2();

int main()//�p�T�t�d
{
	int playMode;
	cout << "���k(�N�X)1�G��H���}�q�K�X�A��̲q�K�X���Ƹ��p�����" << endl;
	cout << "���k(�N�X)2�G��H�P�ɲq�K�X�A�q�������(���p��q������)" << endl;
	cout << "�п�J�Ҧ��N�X�G";

	cin >> playMode;
	if (playMode == 1)
		play1();
	else if (playMode == 2)
		play2();
	else
		cout << "�ÿ�J�A��Ki���F" << endl;
	cout << endl;
	cout << "Game over" << endl;
}

void whoWin(Player& p1, Player& p2)//�p�U�t�d
{
	if (p1.isFailed() || p2.isFailed())
	{
		if (p1.isFailed() && p2.isFailed())
		{
			cout << endl;
			cout << "Draw" << endl;
		}
		else if (p1.isFailed())
		{
			cout << endl;
			cout << "Player2 win" << endl;
		}
		else if (p2.isFailed())
		{
			cout << endl;
			cout << "Player1 win" << endl;
		}
	}
	else
	{
		if (p1.getGuessTimes() < p2.getGuessTimes())
			cout << "Player1 win" << endl;
		else if (p1.getGuessTimes() > p2.getGuessTimes())
			cout << "Player2 win" << endl;
		else if (p1.getGuessTimes() == p2.getGuessTimes())
			cout << "Draw" << endl;
	}
}

void playFunction1(Player& player, int playerNumber)//�p�T�t�d
{
	srand(time(0));
	bool isFinish = 0;

	int max = 100, min = 0;

	int guessNumber = rand() % 101;
	int playerGuessNumber = 0;

	while (!isFinish)
	{
		while (!(playerGuessNumber == guessNumber))//�p�U�t�d
		{
			cout << "Player" << playerNumber << " enter your guess number(range in " << min << "~" << max << "): ";
			cin >> playerGuessNumber;
			if (playerGuessNumber < min || playerGuessNumber > max)
			{
				cout << "Out of range, please enter again" << endl;
			}
			else
			{
				if (playerGuessNumber < guessNumber)
				{
					min = playerGuessNumber + 1;
					if (min == max)//range in 61~61:
					{
						cout << "Ultimate password is " << min << ", you failed." << endl;
						isFinish = 1;
						player.setFailed(true);
						player.plusGuessTimes();
						break;
					}
					else
					{
						cout << "Not ultimate password , please try again." << endl;
						player.plusGuessTimes();
					}
				}

				if (playerGuessNumber > guessNumber)
				{
					max = playerGuessNumber - 1;
					if (min == max)
					{
						cout << "Ultimate password is " << max << ", so you failed." << endl;
						isFinish = 1;
						player.plusGuessTimes();
						player.setFailed(true);
						break;
					}
					else
					{
						cout << "Not ultimate password , please try again." << endl;
						player.plusGuessTimes();
					}
				}
				if (playerGuessNumber == guessNumber)
				{
					cout << "Congratulations! ultimate password is " << guessNumber << endl;
					isFinish = 1;
					player.plusGuessTimes();
				}
			}
		}
	}
}

void playFunction2(Player& player1, Player& player2)//�p�B�t�d
{
	srand(time(0));
	bool isFinish = 0;

	int max = 100, min = 0;

	int guessNumber = rand() % 101;
	int playerGuessNumber = 0;

	Player playerArray[2] = { player1,player2 };
	while (!isFinish)
	{
		for (int i = 0; !(playerGuessNumber == guessNumber); i++)
		{
			cout << "Player" << i % 2 + 1 << " please enter your guess number(range in " << min << "~" << max << ") : ";
			cin >> playerGuessNumber;
			if (playerGuessNumber < min || playerGuessNumber > max)
			{
				cout << "Out of range, please enter again" << endl;
			}
			else
			{
				if (playerGuessNumber < guessNumber)
				{
					min = playerGuessNumber + 1;
					if (min == max)//range in 61~61:
					{
						cout << "Ultimate password is " << min << ", so you failed." << endl;
						isFinish = 1;
						playerArray[i % 2].setFailed(true);
						break;
					}
					else
					{
						cout << "Not ultimate password , please try again." << endl;
					}
				}

				if (playerGuessNumber > guessNumber)
				{
					max = playerGuessNumber - 1;
					if (min == max)
					{
						cout << "Ultimate password is " << max << ", so you failed." << endl;
						isFinish = 1;
						playerArray[i % 2].setFailed(true);
						break;
					}
					else
					{
						cout << "Not ultimate password , please try again." << endl;
					}
				}
				if (playerGuessNumber == guessNumber)
				{
					playerArray[(i + 1) % 2].setFailed(1);
					cout << "Congratulations! ultimate password is " << guessNumber << endl;
					isFinish = 1;
				}
			}
		}
	}
	whoWin(playerArray[0], playerArray[1]);
}

void  play1()//�p�U�t�d
{
	string name1;
	cout << "Enter player1's name: ";
	cin >> name1;
	string name2;
	cout << "Enter player2's name: ";
	cin >> name2;

	Player player1(name1);
	Player player2(name2);
	playFunction1(player1, 1);
	playFunction1(player2, 2);

	cout << "Player1:";
	player1.print();
	cout << "Player2:";
	player2.print();
	whoWin(player1, player2);
}

void  play2()//�p�U�t�d
{
	string name1;
	cout << "Enter player1's name: ";
	cin >> name1;
	string name2;
	cout << "Enter player2's name: ";
	cin >> name2;

	Player player1(name1);
	Player player2(name2);
	playFunction2(player1, player2);
}