/******************************************************
** Program: Zoo_Tycoon.cpp
** Author: 
** Date:
** Description:
** Input:
** Output:
******************************************************/


#include "Lib.h"

using namespace std;

/*Static variable initialization for "Zoo" class*/
double Zoo::m_base_cost_of_food = 25;

/*Static variable initialization for "Animal" class*/
double Animal::m_vet_fee_multiplies = 0.2;

/*Static variable initialization for "Monkey" class*/
int Monkey::m_num_babies = 1;
int Monkey::m_purchase_price = 12000;
double Monkey::m_base_revenue_multiplier = 0.03;
double Monkey::m_food_multiplier = 4;

/*Static variable initialization for "SeaOtter" class*/
int SeaOtter::m_num_babies = 1;
int SeaOtter::m_purchase_price = 4000;
double SeaOtter::m_base_revenue_multiplier = 0.05;
double SeaOtter::m_food_multiplier = 2;

/*Static variable initialization for "MeerKat" class*/
int MeerKat::m_num_babies = 3;
int MeerKat::m_purchase_price = 500;
double MeerKat::m_base_revenue_multiplier = 0.05;
double MeerKat::m_food_multiplier = 1;

/*Money that customer has in the bank*/
int BANK_ACCOUNT = 100000;

/*Day Calculator*/
int num_days = 1;

/*Game Terminal Switch*/
int game_switch = 1;

/*Game Flow 1*/
void DayCalculator();
/*Game Flow 2*/
void RandomEvent();
/*Game Flow 3*/
void CalculateRevenue();

/*Game Conclusion*/
void WeeklyReport();
/*Game Update*/
void IfContinue();

/*********************************************************************
** Function: Main function
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int main()
{
    while (game_switch == 1)
    {
        DayCalculator();
        RandomEvent();
        CalculateRevenue();
        WeeklyReport();
        IfContinue();
        num_days += 7;
    }
    std::cout << "Good Game! The game is over >_< ...";
    return 0;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void DayCalculator()
{
    int num_week = num_days / 7;
    std::cout << "Today is the: " << num_days << "th day (the " << num_week << "th week) !\n";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void RandomEvent() {
    srand((unsigned)time(NULL));
    int Max_event_num = 4;
    int number = rand() % Max_event_num + 1;
    std::cout << "-> Random event #: " << number << " happens!\n";
    switch (number) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void CalculateRevenue()
{

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void WeeklyReport() {
    std::cout << "-> For this week, your total balance in the bank is: $" << BANK_ACCOUNT << ".\n";
    std::cout << "--------------------------------------------------------------------\n";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void IfContinue() {
    std::cout << "Push 'Enter' to continue game, Push any other keys to quit game:\n";
    std::cin >> game_switch;
    std::cout << "\n";
}