#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib> // for exit function
#include <random>


using namespace std;

double OrsteinUhlenbeck(double dt, double theta);
std::default_random_engine generator;

int main()
{
    double theta = 0.0001;
    for(int i = 0; i < 100; i++)
    {
        theta = OrsteinUhlenbeck(0.1,theta);
        cout<<theta<<" "<<"\n";
    }
    return 0;
}

double OrsteinUhlenbeck(double dt, double theta) // A function which increments theta using the exponential of the OrnsteinUhlenbeck process
{

    std::uniform_real_distribution<double> distribution(0.0,1.0);

    double etaB, chiB, PI;
    etaB = 0.5;
    chiB = 0.5;
    PI = 3.142;
    double x, c_norm, c_r1, c_r2, dW;

    // Generate a normal random variable using the Box Muller transform
    c_r1 = distribution(generator);
    c_r2 = distribution(generator);
    c_norm = sqrt(-2 * log(c_r1)) * cos(2 * PI * c_r2);
    dW = sqrt(dt) * c_norm;

    // Get x from theta
    theta = theta*(1/0.0001);
    x = log(theta);
    //cout<<x<<"\n";

    // Now use old x to get new x using Ornstein Uhlenbeck
    x = x - chiB * x * dt + etaB * dW;


    // Now get theta from x
    theta = exp(x);

    theta = theta*0.0001;

    return theta;
}
