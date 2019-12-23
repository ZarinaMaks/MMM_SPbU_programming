/*
 * Реализовать универсальный поиск глобального максимума методом имитации отжига.
 * 
 * Simulated Annealing (SA) is an effective and general form of optimization. 
 * It is useful in finding global optima in the presence of large numbers of local optima.  
 * “Annealing” refers to an analogy with thermodynamics, specifically with the way that metals cool and anneal.
 * Simulated annealing uses the objective function of an optimization problem instead of the energy of a material.
 *
 * The algorithm is basically hill-climbing except instead of picking the best move, it picks a random move. 
 * If the selected move improves the solution, then it is always accepted.
 * Otherwise, the algorithm makes the move anyway with some probability less than 1.
 * The probability decreases exponentially with the “badness” of the move, which is the amount deltaE by which the solution is worsened (i.e., energy is increased.
 *
 * A parameter T is also used to determine this probability.
 * It is analogous to temperature in an annealing system.  At higher values of T, uphill moves are more likely to occur.  
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const double pi = 3.14;
const int D = 1; // - dimension
const int Repeat_num = 5;  // - number of repetitions

// initial and ending "temperature"
const double T_start = 20;
const double T_end = 1;         

struct PartialArgument
{ double val;                 // argument in this dimension
  double A, B;                // limits
};


struct Argument
{ PartialArgument coord[D]; };

double Function(Argument v)    // test function
{
    return abs(sin(v.coord[0].val/2)*(5*sin(v.coord[0].val*(abs(cos(v.coord[0].val+pi/6)/5+1)))+(abs(cos(v.coord[0].val+pi*(abs(cos(v.coord[0].val))+1)))+1)* 0.5*cos(v.coord[0].val*20)));
}

int sign(double x) 
{
    if (x > 0)
    { return 1; }
    else
    { return -1; }
    return 0;
}

bool HaveEvent(double chance)
{
    double event = (double)(rand()) / RAND_MAX;
    
    if (event < chance)
    {return true;}
    else
    {return false;}
}

// Decreasing "temperature" function
double DecreaseTemp(int step)
{ return T_start * pow(0.99, step); }

// Generating random position
Argument GenerateRandomPos(Argument v, double T) 
{
    double a_i = 0;
    double z_i = 0;
    double x_i_new = 0;
    Argument temp;
    
    for (int i = 0; i < D; i++)
    {
        do
        {
            a_i = (double)(rand()) / RAND_MAX;
            z_i = sign(a_i - 0.5) * T * (pow(1 + 1 / T, abs(2 * a_i - 1)) - 1);
            x_i_new = v.coord[i].val + z_i * (v.coord[i].B - v.coord[i].A);
        }
        while (x_i_new < v.coord[i].A || x_i_new > v.coord[i].B);
        temp.coord[i].val = x_i_new;
        temp.coord[i].A = v.coord[i].A;
        temp.coord[i].B = v.coord[i].B;
    }
    return temp;
}

// According to SA formula:
double TransitionChance(double dE, double temp)
{
    return exp(-dE / temp);
}

Argument NewPosition(double (*f)(Argument), Argument v_old, double T)
{
    double dE = 0, E_old = f(v_old);
    Argument v_new;
    
    do
    {
        v_new = GenerateRandomPos(v_old, T);
        dE = E_old - f(v_new);
    }
    while (!HaveEvent(TransitionChance(dE, T)));
    
    return v_new;
}

ostream& operator<< (ostream &out, Argument x)
{
    out << " ";
    for (int i = 0; i < D; i++)
    {
        out << x.coord[i].val;
        if (i < D - 1)
        {
            out << ", ";
        }
    }
    out << " ";
    
    return out;
}

void Initialisation(Argument &v_start)
{
    cout << "Left and right border of searching area (A & B): " << endl;
    for (int i = 0; i < D; i++)
    {
        cin >> v_start.coord[i].A >> v_start.coord[i].B;
        v_start.coord[i].val = v_start.coord[i].A + ((double)(rand()) / RAND_MAX) * (v_start.coord[i].B - v_start.coord[i].A);
    }
}

double GlobalMax(double (*f)(Argument), Argument start, Argument &v_max)
{
    Argument v;
    int step = 0;
    double max = 0, f_val = 0, T = T_start;
    
    // Simulated annealing //
    max = f(start);
    v = start;
    while (T > T_end)
    {
        step++;
        T = DecreaseTemp(step);
        v = NewPosition(f, v, T);
        f_val = f(v);
        if (max < f_val)
        {
            max = f_val;
            v_max = v;
        }
    }
    return max;
}

int main()
{
    srand(time(0));
    Argument v_start, v_max, precise_max_point;
    double precise_max_value = 0, max_value = 0;
    
    // Initialising starting and ending point:
    Initialisation(v_start);
    max_value = Function(v_start);
    
    // Precising
    for (int i = 0; i < Repeat_num; i++)
    {
        max_value = GlobalMax(Function, v_start, v_max);
        if (max_value > precise_max_value || i == 0)
        {
            precise_max_value = max_value;
            precise_max_point = v_max;
        }
    }
    
    cout << "Maximum:" << precise_max_point << endl;
    return 0;
}

