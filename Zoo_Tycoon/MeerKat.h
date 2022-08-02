/******************************************************
** Program: MeerKat.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include"Animal.h"

class MeerKat: public Animal
{
public:
	using Animal::Animal; //Inherited constructors
	MeerKat() {};
	~MeerKat() {};

public:
	static int m_num_babies;
	static int m_purchase_price;
	static double m_base_revenue_multiplier;
	static double m_food_multiplier;

public:
	double CalcFoodCost();
	double CalcRevenue();
	double CalcVetFee();
};

