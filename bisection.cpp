#include <iostream>
#include <cmath>

using namespace std;

// Quadratic function for which we want to find the root.
double function(double x, double a, double b, double c)
{
    return a * x * x + b * x + c;
}

// Bisection method to find the root of a function within an interval [a, b].
double bisection(double a, double b, double tolerance, double coeff_a, double coeff_b, double coeff_c)
{
    double fa = function(a, coeff_a, coeff_b, coeff_c);
    double fb = function(b, coeff_a, coeff_b, coeff_c);

    if (fa * fb >= 0)
    {
        cout << "Error: The function values at endpoints have the same sign." << endl;
        return 0.0; // Not a valid interval.
    }

    double c;
    int iteration = 0;
    while ((b - a) >= tolerance)
    {
        c = (a + b) / 2.0;
        double fc = function(c, coeff_a, coeff_b, coeff_c);

        if (fc == 0.0)
        {
            return c; // Found the root.
        }
        else if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        iteration++;
        cout << "Iteration " << iteration << ": Approximate root = " << (a + b) / 2.0 << endl;
    }

    return (a + b) / 2.0;
}

int main()
{
    double a, b, c;

    cout << "Enter the coefficients of the quadratic equation ax^2 + bx + c:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    double tolerance;
    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tolerance;

    double lower_endpoint, upper_endpoint;
    cout << "Enter the lower endpoint of the interval: ";
    cin >> lower_endpoint;
    cout << "Enter the upper endpoint of the interval: ";
    cin >> upper_endpoint;

    double root = bisection(lower_endpoint, upper_endpoint, tolerance, a, b, c);

    cout << "Approximate root: " << root << endl;

    return 0;
}
