#include <iostream>
#include <cmath>

using namespace std;

// Define the function for which you want to find the root.
double function(double x)
{
    return x * x - 4; // Replace with your own function.
}

// Regula Falsi method to find the root of a function within an interval [a, b].
double regulaFalsi(double a, double b, double tolerance)
{
    double fa = function(a);
    double fb = function(b);

    if (fa * fb >= 0)
    {
        cout << "Error: The function values at endpoints have the same sign." << endl;
        return 0.0; // Not a valid interval.
    }

    double c;
    int iteration = 0;
    while (fabs(b - a) >= tolerance)
    {
        c = (a * fb - b * fa) / (fb - fa);
        double fc = function(c);

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
        cout << "Iteration " << iteration << ": Approximate root = " << c << endl;
    }

    return c;
}

int main()
{
    double a, b, tolerance;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tolerance;

    double root = regulaFalsi(a, b, tolerance);

    cout << "Approximate root: " << root << endl;

    return 0;
}
