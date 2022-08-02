/******************************************************
** Program: Zoo.cpp
** Author:
** Date:
** Description:
******************************************************/
#include "Zoo.h"

/*********************************************************************
** Function: Constructor
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Zoo::Zoo() {
	m_roster = new Animal * [m_cap];
}

/*********************************************************************
** Function: Destructor
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Zoo::~Zoo() {
	//if (m_roster != nullptr)
	//{
	//	for (int i = 0; i < m_num; i++)
	//	{
	//		delete[]m_roster[i];
	//	}
	//}
	delete[] m_roster;
}

/*********************************************************************
** Function: Copy Constructor
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Zoo::Zoo(const Zoo& p) {

}

/*********************************************************************
** Function: Assignment Operator
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Zoo& Zoo::operator=(const Zoo& p) {
	//...
	return *this;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Zoo::ExpandCapacity() {
	m_cap *= 2;
	Animal** tmp = new Animal * [m_cap];
	for (int i = 0; i < m_num; i++)
	{
		tmp[i] = m_roster[i];
	}
	delete[] m_roster;
	m_roster = tmp;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
double Zoo::CalcFoodCost() {
	double sum = 0;
	for (int i = 0; i < m_num; i++)
	{
		sum += m_roster[i]->CalcFoodCost();
	}
}