#ifndef Player_H
#define Player_H
#include<iostream>
using namespace std;

class Player
{
public:
	Player();
	Player(string);
	void setName(string);//�]�w�W�r
	string getName()const;
	void setGuessTimes(int);//���s�q�o����
	void plusGuessTimes();//�C�q�@���N++
	int getGuessTimes()const;
	void setFailed(bool);//�]�w���S���q�z
	bool isFailed()const;//�P�w���S���q�z
	void print();
private:
	string name;//�W�r
	bool failed = false;//�]�w���S���q�z
	int guessTimes;//�s���q�o����
};

#endif // !Player_H

