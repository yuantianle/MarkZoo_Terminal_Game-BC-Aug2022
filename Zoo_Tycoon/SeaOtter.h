/******************************************************
** Program: SeaOtter.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include"Animal.h"

class SeaOtter: public Animal
{
public:
	using Animal::Animal; /*Inherited constructors*/
	SeaOtter() {}
	SeaOtter(int age) :Animal(age) { m_type = 2; }
	~SeaOtter() {}
	
public:
	static int m_num_babies;
	static int m_purchase_price;
	static double m_base_revenue_multiplier;
	static double m_food_multiplier;

public:
	double CalcFoodCost() { return 0.0; }
	double CalcRevenue() { return 0.0; }
	double CalcVetFee() { return 0.0; }
};

