/******************************************************
** Program: Zoo.h
** Author:
** Date:
** Description:
******************************************************/
#pragma once
#include "Animal.h"
class Zoo
{
public:
	Zoo();
	~Zoo();
	Zoo(const Zoo& p);
	Zoo& operator=(const Zoo& p);
	
public:
	Animal** m_roster;
	int m_cap = 10;
	int m_num = 0;
	double m_bank_balance = 100000;

	static double m_base_cost_of_food;


public:
	void ExpandCapacity();
	double CalcFoodCost();
};

