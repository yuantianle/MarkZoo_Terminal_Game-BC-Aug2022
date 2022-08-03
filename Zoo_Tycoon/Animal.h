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

public:
	static int m_teen_weeks; /*(m_baby_weeks, m_teen_weeks] */
	static int m_adult_weeks; /*(m_baby_weeks, m_adult_weeks] */
	static double m_vet_fee_multiplies;

public:
	virtual double CalcFoodCost() = 0;
	virtual double CalcRevenue(double bounus_price) = 0;
	virtual double CalcVetFee() = 0;
};

