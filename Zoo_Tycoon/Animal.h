/******************************************************
** Program: Animal.h
** Author: 
** Date:
** Description:
** Input:
** Output:
******************************************************/
#include <iostream>
#include <stdlib.h>

#pragma once
class Animal
{
public:
	Animal();
	Animal(int age);
	~Animal();

public:
	int m_age;
	int m_type;
	bool m_if_sick = false;

public:
	static double m_vet_fee_multiplies;

public:
	virtual double CalcFoodCost() = 0;
	virtual double CalcRevenue() = 0;
	virtual double CalcVetFee() = 0;
};

