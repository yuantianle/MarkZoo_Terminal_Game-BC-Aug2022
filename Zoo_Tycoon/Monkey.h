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
	using Animal::Animal; /*Inherited constructors*/
	Monkey() {}
	Monkey(int age) :Animal(age) { m_type = 1; }
	~Monkey() {}

public:
	static int m_num_babies;
	static int m_purchase_price;
	static double m_base_revenue_multiplier;
	static double m_food_multiplier;
	static bool m_boom_flag;

public:
	/*********************************************************************
	** Function:
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	double CalcFoodCost() { return m_food_multiplier; }
	double CalcRevenue(double bounus_price) {
		double gain = m_purchase_price * m_base_revenue_multiplier;
		if (m_age < m_teen_weeks)
			gain *= 2.0;
		if (m_boom_flag)
			gain += bounus_price;
		return gain;
	}
	double CalcVetFee() {
		double cost = m_purchase_price * m_vet_fee_multiplies;
		return cost;
	}

};

