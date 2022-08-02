/******************************************************
** Program: Animal.h
** Author: 
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
class Animal
{
public:
	Animal() {};
	~Animal() {};

public:
	int m_age;
	static int m_baby_weeks; /*(0, m_baby_weeks] */
	static int m_teen_weeks; /*(m_baby_weeks, m_teen_weeks] */
	static int m_adult_weeks; /*(m_baby_weeks, m_adult_weeks] */
	static double m_vet_fee_multiplies;

public:
	virtual double CalcFoodCost() = 0;
	virtual double CalcRevenue() = 0;
	virtual double CalcVetFee() = 0;
};

