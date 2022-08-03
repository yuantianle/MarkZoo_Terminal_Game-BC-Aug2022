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
	int m_cap = 100;
	int m_num = 0;
	int m_monk_num = 0;
	int m_seao_num = 0;
	int m_meer_num = 0;
	double m_bank_balance = 100000;

public:
	static int m_teen_weeks; /*(m_baby_weeks, m_teen_weeks] */
	static int m_adult_weeks; /*(m_baby_weeks, m_adult_weeks] */
	static double m_base_cost_of_food;

public:
	void ExpandCapacity();
	double CalcFoodCost();
};

