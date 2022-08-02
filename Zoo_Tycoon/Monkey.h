/******************************************************
** Program: Monkey.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include"Animal.h"

class Monkey: public Animal
{
public:
	using Animal::Animal; //Inherited constructors
	Monkey() {};
	~Monkey() {};

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

