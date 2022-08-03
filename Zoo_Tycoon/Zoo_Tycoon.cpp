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
int Zoo::m_teen_weeks = 7; /*(0, m_teen_weeks] */
int Zoo::m_adult_weeks = 52; /*(m_baby_weeks, m_adult_weeks] */

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

/*Zoo*/
Zoo* m_zoo = new Zoo();

/*Day Calculator*/
int m_num_days = 1;

/*Game Terminal Switch*/
int game_switch = 1;

/*Game Flow 1*/
void DayCalculator();
/*Game Flow 2*/
void RandomEvent();
/*Game Flow 3*/
void CalculateRevenue();
/*Game Flow 4*/
void ProcessPurchase();
void purchase(int aniindex, int num);
void get_int(int& d, std::string prompt, std::string fail);
void get_int_between(int& d, int min, int max, std::string prompt, std::string fail);
/*Game Flow 5*/
void ProcessFeedFee();


/*Game Conclusion*/
void WeeklyReport();
void showbalance();
void showtable();

/*Game Update*/
void GGCondition();
void if_continue();

/*Extra Module*/
void SpeedUp();

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

        if (m_num_days != 1)
            RandomEvent();
        else
            cout << "Let's initial your Zoo!\n";

        CalculateRevenue();
        ProcessPurchase();
        ProcessFeedFee();

        WeeklyReport();
        GGCondition();
        m_num_days += 7;
    }
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
    int num_week = m_num_days / 7;
    std::cout << "Today is the: " << m_num_days << "th day (the " << num_week << "th week)!\n";
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
void CalculateRevenue(){

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void ProcessPurchase() {
    std::cout << "Please choose the single species options below for your purchase this week:\n";
    std::cout << "1. Monkey    2. Sea otter    3. Meerkats    4.Don't purchase anything\n";
    int choise = -1;
    get_int(choise, "", "WARNNIG: Please input digit as your choice: 1 / 2 / 3 / 4:\n");
    while (choise != 1 && choise != 2 && choise != 3 && choise != 4)
    {
        get_int(choise, "WARNNIG: Please input following digit as your choice: 1 / 2 / 3 / 4:\n", "");
    }
    int MAX_NUM = 100;
    int num;
    switch (choise) {
    case 1:
        std::cout << "Please enter the quantity of adult Monkey you want to purchase:\n";
        get_int(num, "", "WARNNIG: Please enter integer as quantity:\n");
        if (num < 0)
        {
            get_int_between(num,0,INT_MAX, "WARNNIG: Please enter legal(positive) quantity of adult Monkey:\n", "");
        }
        if (num > 100)
        {
            std::cout << "Since we only accept 100 as a week purchase maximum quantity, we processed 100 for your purchase at this time.\n";
            num = 100;
        }
        purchase(1, num);
        break;
    case 2:
        std::cout << "Please enter the quantity of adult Sea otter you want to purchase:\n";
        get_int(num, "", "WARNNIG: Please enter integer as quantity:\n");
        if (num < 0)
        {
            get_int_between(num, 0, INT_MAX, "WARNNIG: Please enter legal(positive) quantity of adult Sea otters:\n", "");
        }
        if (num > 100)
        {
            std::cout << "Since we only accept 100 as a week purchase maximum quantity, we processed 100 for your purchase at this time.\n";
            num = 100;
        }
        purchase(2, num);
        break;
    case 3:
        std::cout << "Please enter the quantity of adult Meerkats you want to purchase:\n";
        get_int(num, "", "WARNNIG: Please enter integer as quantity:\n");
        if (num < 0)
        {
            get_int_between(num, 0, INT_MAX, "WARNNIG: Please enter legal(positive) quantity of adult Meerkats:\n", "");
        }
        if (num > 100)
        {
            std::cout << "Since we only accept 100 as a week purchase maximum quantity, we processed 100 for your purchase at this time.\n";
            num = 100;
        }
        purchase(3, num);
        break;
    case 4:
        std::cout << "You do not purchase anything this week.\n";
        break;
    }
    return;
}

/*********************************************************************
** Function:
** Description: 1.Monkey 2.SeaOtter 3.Meerkat
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void purchase(int aniindex, int num) {
    /*check if zoo cannot hold so many animals (include new added animals)*/
    if (num + m_zoo->m_num > m_zoo->m_cap)
    {
        m_zoo->ExpandCapacity();
    }

    /*add animals into the zoo*/
    switch (aniindex)
    {
    case 1:
        for (int i = 0; i < num; i++)
        {
            Monkey* monk = new Monkey(52);
            m_zoo->m_roster[m_zoo->m_num] = monk;
            m_zoo->m_num += 1;
            m_zoo->m_monk_num += 1;
        }
        break;
    case 2:
        for (int i = 0; i < num; i++)
        {
            SeaOtter* seao = new SeaOtter(52);
            m_zoo->m_roster[m_zoo->m_num] = seao;
            m_zoo->m_num += 1;
            m_zoo->m_seao_num += 1;
        }
        break;
    case 3:
        for (int i = 0; i < num; i++)
        {
            MeerKat* meer = new MeerKat(52);
            m_zoo->m_roster[m_zoo->m_num] = meer;
            m_zoo->m_num += 1;
            m_zoo->m_meer_num += 1;
        }
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
void get_int(int& d, std::string prompt, std::string fail)
{
    while (1) {

        std::cout << prompt;
        std::string str;
        std::cin >> str;

        std::istringstream ss(str);
        int val1;
        ss >> val1;

        if (!ss.eof()) {
            std::cout << fail;
            continue;
        }
        else {
            d = val1;
            break;
        }
    }
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void get_int_between(int& d, int min, int max, std::string prompt, std::string fail)
{
    while (1) {
        get_int(d, prompt, fail);
        if (d > max || d < min) {
            std::cout << "Sorry, your choice is out of range.\n";
            continue;
        }
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
void ProcessFeedFee() {
    std::cout << "-> The total feeding cost of this week is: $xxx.\n";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void WeeklyReport() {
    showbalance();
    showtable();
    std::cout << "--------------------------------------------------------------------\n";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void showbalance() {
    std::cout << "-> For this week, your total balance in the bank is: $" << m_zoo->m_bank_balance << ".\n";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void showtable() {
    int monk_baby_num = 0;
    int monk_teen_num = 0;
    int monk_adult_num = 0;

    int seao_baby_num = 0;
    int seao_teen_num = 0;
    int seao_adult_num = 0;

    int meer_baby_num = 0;
    int meer_teen_num = 0;
    int meer_adult_num = 0;

    for (int i = 0; i < m_zoo->m_num; i++)
    {
        Animal* ani = m_zoo->m_roster[i];
        int q = ani->m_type;
        switch (q) {
        case 1:
            if (ani->m_age < m_zoo->m_teen_weeks)
            {
                monk_baby_num += 1;
            }
            else if (ani->m_age >= m_zoo->m_teen_weeks && ani->m_age < m_zoo->m_adult_weeks)
            {
                monk_teen_num += 1;
            }
            else
            {
                monk_adult_num += 1;
            }
            ani->m_age += 1;
            break;
        case 2:
            if (ani->m_age < m_zoo->m_teen_weeks)
            {
                seao_baby_num += 1;
            }
            else if (ani->m_age >= m_zoo->m_teen_weeks && ani->m_age < m_zoo->m_adult_weeks)
            {
                seao_teen_num += 1;
            }
            else
            {
                seao_adult_num += 1;
            }
            ani->m_age += 1;
            break;
        case 3:
            if (ani->m_age < m_zoo->m_teen_weeks)
            {
                meer_baby_num += 1;
            }
            else if (ani->m_age >= m_zoo->m_teen_weeks && ani->m_age < m_zoo->m_adult_weeks)
            {
                meer_teen_num += 1;
            }
            else
            {
                meer_adult_num += 1;
            }
            ani->m_age += 1;
            break;
        }
    }

    std::cout << "====================================================\n";
    std::cout << "Total num of animal: " << m_zoo->m_num << endl;

    std::cout << "Total num of Monkey: " << m_zoo->m_monk_num << endl;    
    std::cout << "Total num of Sea otter: " << m_zoo->m_seao_num << endl;
    std::cout << "Total num of Meerkat: " << m_zoo->m_meer_num << endl;

    std::cout << "Total baby num of Monkey: " << monk_baby_num << endl;
    std::cout << "Total baby num of Sea otter: " << seao_baby_num << endl;
    std::cout << "Total baby num of Meerkat: " << meer_baby_num << endl;

    std::cout << "Total teen num of Monkey: " << monk_teen_num << endl;
    std::cout << "Total teen num of Sea otter: " << seao_teen_num << endl;
    std::cout << "Total teen num of Meerkat: " << meer_teen_num << endl;

    std::cout << "Total adult of Monkey: " << monk_adult_num << endl;
    std::cout << "Total adult of Sea otter: " << seao_adult_num << endl;
    std::cout << "Total adult of Meerkat: " << meer_adult_num << endl;
    std::cout << "====================================================\n";

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void GGCondition() {
    if (m_zoo->m_bank_balance <= 0)
    {
        game_switch = 2;
        std::cout << "The game ends with the zoo going bankrup. GG >_< !\n";
    }
    else
    {
        if_continue();
    }
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void if_continue() {
    std::cout << "Push 'Enter' to continue game, Push any other keys to quit game:\n";
    std::cin >> game_switch;
    if (game_switch != 1)
        std::cout << "You have quit the game. See you next time >_< ...";
}