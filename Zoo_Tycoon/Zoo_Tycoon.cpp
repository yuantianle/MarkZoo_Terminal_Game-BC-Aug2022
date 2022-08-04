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
int Zoo::m_teen_weeks = 7; /*(0, m_teen_weeks] */
int Zoo::m_adult_weeks = 52; /*(m_baby_weeks, m_adult_weeks] */
double Zoo::m_base_cost_of_food = 25;


/*Static variable initialization for "Animal" class*/
int Animal::m_teen_weeks = 7; /*(0, m_teen_weeks] */
int Animal::m_adult_weeks = 52; /*(m_baby_weeks, m_adult_weeks] */
double Animal::m_vet_fee_multiplies = 0.2;

/*Static variable initialization for "Monkey" class*/
int Monkey::m_num_babies = 1;
int Monkey::m_purchase_price = 12000;
double Monkey::m_base_revenue_multiplier = 0.03;
double Monkey::m_food_multiplier = 4;
bool Monkey::m_boom_flag = false;

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

/*Cost*/
double m_weekly_earn = 0; /*Animal Revenue*/
double m_weekly_fcost = 0;/*Food Cost*/
double m_weekly_pcost = 0;/*Perchase Cost*/

/*Counter*/
int monk_baby_num = 0;
int monk_teen_num = 0;
int monk_adult_num = 0;

int seao_baby_num = 0;
int seao_teen_num = 0;
int seao_adult_num = 0;

int meer_baby_num = 0;
int meer_teen_num = 0;
int meer_adult_num = 0;

/*Revenue bounus price*/
double bounus_price = 0;

/*Game Terminal Switch*/
char game_switch = 'Y';

/*Game Flow 1*/
void DayCalculator();
/*Game Flow 2*/
void RandomEvent();
void event1();
void event2();
void event3();

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

/*Beauty Format*/
void FormatFunction(int n, bool a);
void FormatFunction2(int n);
void FormatFunction3(int n);
void ArrowFunction();
void Title();

/*********************************************************************
** Function: Main function
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int main()
{
    setupConsole();
    Title();
    while (game_switch == 'Y' || game_switch == 'y')
    {
        DayCalculator();

        if (m_num_days != 1)
            RandomEvent();
        else
        {
            FormatFunction(1, true); cout << "Let's initial your Zoo!\n";
            RandomEvent();
        }

        CalculateRevenue();
        ProcessPurchase();
        ProcessFeedFee();

        WeeklyReport();
        GGCondition();
        m_num_days += 7;
    }
    cout << "\033[31m\033[0m";
    restoreConsole();
    return 0;
}

void Title() {
    cout << "\033[31m\033[8m" << endl;
    std::cout << "=============================================================================================\n";
    std::cout << "        / |   / |  | _\\\\    | ____\\  ||    //    /---------  ------------  ------------                " << endl;
    std::cout << "       //||  //||  ||  \\\\   ||    \\\\ ||___//    /------- /    \\ ------- \\   \\ ------- \\            " << endl;
    std::cout << "      // || // ||  ||___\\\\  ||____// ||---\\\\          / /      \\ \\     \\ \\   \\ \\     \\ \\       " << endl;
    std::cout << "     //  ||//  ||  ||    \\\\ ||    \\\\ ||    \\\\        / /_______ \\ \\_____\\ \\   \\ \\_____\\ \\      " << endl;
    std::cout << "    --   ---   --  --     ----    -----    ---      /_________/  \\ ________\\   \\_________\\        " << endl;
    std::cout << "=============================================================================================";
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

    cout << "\033[34m\033[1m" << endl;
    std::cout << "\n*************************** Today is the: " << m_num_days << "th day (the " << num_week << "th week)! ***************************\n";
    FormatFunction2(1); cout << "\033[33m\033[1m"; std::cout << "Your account balance so far is: $" << m_zoo->m_bank_balance << ".\n";
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
    FormatFunction3(1); std::cout << "Random event #: " << number << " happens!\n";
    switch (number) {//number
    case 1:
        event1();
        break;
    case 2:
        event2();
        break;
    case 3:
        event3();
        break;
    case 4:
        FormatFunction(1, true); std::cout << "No special event occurs during this week.\n";
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
void event1() {
    if (m_zoo->m_num < 1)
    {
        FormatFunction(1, true); std::cout << "There are no enough number of animals for Even1 to happen. Please buy some animals.\n";
    }
    else {
        string animal;
        double recover_cost;
        srand((unsigned)time(NULL));
        int Max_event_num = m_zoo->m_num;
        int number = rand() % Max_event_num + 1;
        switch (m_zoo->m_roster[number - 1]->m_type) {
        case 1:
            animal = "Monkey";
            recover_cost = Animal::m_vet_fee_multiplies * Monkey::m_purchase_price;
            break;
        case 2:
            animal = "Sea Otter";
            recover_cost = Animal::m_vet_fee_multiplies * SeaOtter::m_purchase_price;
            break;
        case 3:
            animal = "MeerKat";
            recover_cost = Animal::m_vet_fee_multiplies * MeerKat::m_purchase_price;
            break;
        }
        FormatFunction(1, true); std::cout << "There is a " << animal << " getting sick.\n";
        if (m_zoo->m_bank_balance >= recover_cost)
        {
            FormatFunction(3, true); std::cout << "You have rescued the " << animal << ".\n";
            m_zoo->m_bank_balance -= recover_cost;
            FormatFunction2(3); std::cout << "Balance of bank: $" << m_zoo->m_bank_balance << ".\n";
        }
        else
        {
            switch (m_zoo->m_roster[number - 1]->m_type) {
            case 1:
                delete m_zoo->m_roster[number - 1];
                m_zoo->m_roster[number - 1] = NULL;
                m_zoo->m_num -= 1;
                m_zoo->m_monk_num -= 1;
                break;
            case 2:
                delete m_zoo->m_roster[number - 1];
                m_zoo->m_roster[number - 1] = NULL;
                m_zoo->m_num -= 1;
                m_zoo->m_seao_num -= 1;
                break;
            case 3:
                delete m_zoo->m_roster[number - 1];
                m_zoo->m_roster[number - 1] = NULL;
                m_zoo->m_num -= 1;
                m_zoo->m_meer_num -= 1;
                break;
            }
            FormatFunction(3, true); std::cout << "The " << animal << " died because your cannot pay for the medication.\n";
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
void event2() {
    if (m_zoo->m_num < 2)
    {
        FormatFunction(1, true); std::cout << "There are no enough number of animals for Even2 to happen.\n";
    }
    else {
        string animal;
        srand((unsigned)time(NULL));
        int Max_event_num = m_zoo->m_num;
        int number = rand() % Max_event_num + 1;
        while (m_zoo->m_roster[number - 1]->m_age < Zoo::m_adult_weeks)
        {
            srand((unsigned)time(NULL));
            int number = rand() % Max_event_num + 1;
        }
        int MAX_BIRTH_NUM = 10;
        srand((unsigned)time(NULL));
        int birth_num = rand() % MAX_BIRTH_NUM + 1;
        if (birth_num + m_zoo->m_num > m_zoo->m_cap)
        {
            m_zoo->ExpandCapacity();
        }
        switch (m_zoo->m_roster[number - 1]->m_type) {
        case 1:
            animal = "Monkey";
            if (monk_adult_num < 2)
            {
                FormatFunction(1, true); std::cout << "Chose " << animal << ", but this species do not have enough adult num for brith.\n";
                break;
            }
            else
            {
                for (int i = 0; i < birth_num; i++)
                {
                    Monkey* monk = new Monkey(0);
                    m_zoo->m_roster[m_zoo->m_num] = monk;
                    m_zoo->m_num += 1;
                    m_zoo->m_monk_num += 1;
                }
                FormatFunction(1, true); std::cout << "There are " << birth_num << " " << animal << "s borned.\n";
                break;
            }
        case 2:
            animal = "Sea Otter";
            if (seao_adult_num < 2)
            {
                FormatFunction(1, true); std::cout << "Chose " << animal << ", but this species do not have enough adult num for brith.\n";
                break;
            }
            else
            {
                for (int i = 0; i < birth_num; i++)
                {
                    SeaOtter* seao = new SeaOtter(0);
                    m_zoo->m_roster[m_zoo->m_num] = seao;
                    m_zoo->m_num += 1;
                    m_zoo->m_seao_num += 1;
                }
                FormatFunction(1, true); std::cout << "There are " << birth_num << " " << animal << "s borned.\n";
                break;
            }
        case 3:
            animal = "MeerKat";
            if (meer_adult_num < 2)
            {
                FormatFunction(1, true); std::cout << "Chose " << animal << ", but this species do not have enough adult num for brith.\n";
                break;
            }
            else
            {
                for (int i = 0; i < birth_num; i++)
                {
                    MeerKat* meer = new MeerKat(0);
                    m_zoo->m_roster[m_zoo->m_num] = meer;
                    m_zoo->m_num += 1;
                    m_zoo->m_meer_num += 1;
                }
                FormatFunction(1, true); std::cout << "There are " << birth_num << " " << animal << "s borned.\n";
                break;
            }
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
void event3() {
    if (m_zoo->m_monk_num < 1)
    {
        FormatFunction(1, true); std::cout << "There are no enough number of Monkies for Even3 to happen.\n";
    }
    else
    {
        Monkey::m_boom_flag = true;
        srand((unsigned)time(NULL));
        bounus_price = rand() % 700 + 500.0;
        FormatFunction(1, true); std::cout << "Lucky! During this week, each monkey will earn $" << bounus_price << " more!\n";
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
    double sum = m_zoo->CalcRevenue(bounus_price);
    FormatFunction3(1); std::cout << "The total revenue of all the animals in this week is: $" << sum << ".\n";
    m_weekly_earn = sum;
    m_zoo->m_bank_balance += m_weekly_earn;
    FormatFunction2(3); std::cout << "Balance of bank: $" << m_zoo->m_bank_balance << ".\n";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void ProcessPurchase() {    
     FormatFunction3(1); std::cout << "Please choose the single species options below for your purchase this week:\n";
     FormatFunction2(3); std::cout << "Your total balance in your account is: $" << m_zoo->m_bank_balance << ".\n";

    FormatFunction(3, false); std::cout << "======================================================================================\n";
    FormatFunction(3, false); std::cout << "| Species |  1. Monkey   |  2. Sea otter  |  3. Meerkats  | 4.Don't purchase anything|\n";
    FormatFunction(3, false); std::cout << "|  Price  |  $12,000.0   |    $4,000.0    |    $500.0     |           $0.0           |\n";
    FormatFunction(3, false); std::cout << "======================================================================================\n";
    int choise = -1;
    get_int(choise, "", "WARNNIG: Please press digit key for your choice: 1 / 2 / 3 / 4:\n");
    while (choise != 1 && choise != 2 && choise != 3 && choise != 4)
    {
        get_int(choise, "WARNNIG: Please press following digit key for your choice: 1 / 2 / 3 / 4:\n", "");
    }
    int MAX_NUM = 100;
    int num;
    FormatFunction(4, false); 
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

    int sum = 0;
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
        sum += Monkey::m_purchase_price * num;
        break;
    case 2:
        for (int i = 0; i < num; i++)
        {
            SeaOtter* seao = new SeaOtter(52);
            m_zoo->m_roster[m_zoo->m_num] = seao;
            m_zoo->m_num += 1;
            m_zoo->m_seao_num += 1;
        }
        sum += Monkey::m_purchase_price * num;
        break;
    case 3:
        for (int i = 0; i < num; i++)
        {
            MeerKat* meer = new MeerKat(52);
            m_zoo->m_roster[m_zoo->m_num] = meer;
            m_zoo->m_num += 1;
            m_zoo->m_meer_num += 1;
        }
        sum += Monkey::m_purchase_price * num;
        break;
    }   
    FormatFunction3(1); std::cout << "The total animal purchase cost of this week is: $" << sum << ".\n";
    m_weekly_pcost = sum;
    m_zoo->m_bank_balance -= m_weekly_pcost;
    FormatFunction2(3); std::cout << "Balance of bank: $" << m_zoo->m_bank_balance << ".\n";
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
        std::string str;
        if (prompt == "")
        {
            FormatFunction(3, false);ArrowFunction();  std::cin >> str;
            std::istringstream ss(str);
            int val1;
            ss >> val1;

            if (!ss.eof()) {
                FormatFunction(4, false);     
                cout << "\033[31m\033[1m"; 
                std::cout << fail;
                cout << "\033[33m\033[1m";
                continue;
            }
            else {
                d = val1;
                break;
            }
        }
        else
        {
            FormatFunction(4, false); 
            cout << "\033[31m\033[1m";
            std::cout << prompt;
            cout << "\033[33m\033[1m";
            FormatFunction(3, false); ArrowFunction();  std::cin >> str;
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
            FormatFunction(4, false); std::cout << "Sorry, your choice is out of range.\n";
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
    double sum = m_zoo->CalcFoodCost();
    FormatFunction3(1); std::cout << "The total animal feeding cost of this week is: $"<< sum <<".\n";
    m_weekly_fcost = sum;
    m_zoo->m_bank_balance -= m_weekly_fcost;
    FormatFunction2(3); std::cout << "Balance of bank: $" << m_zoo->m_bank_balance << ".\n";
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
    FormatFunction(1, true); std::cout << "At the end of this week, your total balance in the bank is: $" << m_zoo->m_bank_balance << ".";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void showtable() {
    monk_baby_num = 0;
    monk_teen_num = 0;
    monk_adult_num = 0;

    seao_baby_num = 0;
    seao_teen_num = 0;
    seao_adult_num = 0;

    meer_baby_num = 0;
    meer_teen_num = 0;
    meer_adult_num = 0;

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
    std::cout << "\n";
    FormatFunction(1, true); std::cout << "Here is the check list of the animals in the zoo now:\n";
    cout << "\033[33m\033[1m";
    FormatFunction(1, false); std::cout << "=====================================================\n";
    FormatFunction(1, false); std::cout << "|  Species  |   Monkey   |  Sea otter  |  Meerkats  |\n";
    FormatFunction(1, false); std::cout << "-----------------------------------------------------\n";
    FormatFunction(1, false); std::cout << "|    Baby   |     " << monk_baby_num << "      |      " << seao_baby_num << "      |     " << meer_baby_num << "      |\n";
    FormatFunction(1, false); std::cout << "| Adolescent|     " << monk_teen_num << "      |      " << seao_teen_num << "      |     " << meer_teen_num << "      |\n";
    FormatFunction(1, false); std::cout << "|   Adult   |     " << monk_adult_num << "      |      " << seao_adult_num << "      |     " << meer_adult_num << "      |\n";
    FormatFunction(1, false); std::cout << "|   Total   |     " << m_zoo->m_monk_num << "      |      " << m_zoo->m_seao_num << "      |     " << m_zoo->m_meer_num << "      |\n";
    FormatFunction(1, false); std::cout << "-----------------------------------------------------\n";
    FormatFunction(1, false); std::cout << "| All number|                   " << m_zoo->m_num << "                   |\n"; 
    FormatFunction(1, false); std::cout << "=====================================================\n";
    cout << "\033[36m\033[1m";
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
        cout << "\033[31m\033[1m";
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
    std::cout << "Press 'Y(y)' to continue to the next week, Press any other keys to quit game:\n";
    std::cin >> game_switch;
    std::cout << endl;
    if (game_switch != 'Y' && game_switch != 'y')
    {
        cout << "\033[31m\033[1m";
        std::cout << "You have quit the game. See you next time >_< ...";
    }
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void FormatFunction(int n, bool arrowon) {

    std::string s = "";
    for (int i = 0; i < n; i++)
    {
        s += "  ";
    }
    if (arrowon) { 
        cout << "\033[36m\033[1m";
        std::cout << s << "|  " << endl;
        std::cout << s << "-->";
    }
    else
    {
        std::cout << s;
    }
}
void FormatFunction2(int n) {
    std::string s = "";
    for (int i = 0; i < n; i++)
    {
        s += "  ";
    }
    cout << "\033[36m\033[1m";
    std::cout << s << "|  " << endl;
    cout << "\033[33m\033[1m";
    std::cout << s << "~>";
}
void FormatFunction3(int n) {
    std::string s = "";
    std::string q = "";
    for (int i = 0; i < n; i++)
    {
        s += "  ";
        q += "==";
    }
    cout << "\033[36m\033[1m";
    std::cout << s << "|  " << endl;
    cout << "\033[32m\033[1m";
    std::cout << q << "==>";
}
void ArrowFunction() {
    cout << "\033[33m\033[1m";
    std::cout << "=>";
}