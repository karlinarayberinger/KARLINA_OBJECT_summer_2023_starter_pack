/**
 * file: square_root_approximation.cpp
 * type: C++ (source file)
 * date: 17_JUNE_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/* preprocessing directives */
#include <iostream> // standard input (std::cin), standard output (std::cout)
#include <fstream> // file input, file output
#define MAXIMUM_X 100 // constant which represents maximum absolute value of the program input value
#define EPSILON 0.00000001 // constant which represents the degree of accuracy of the square root approximation 

/* function prototypes */
float absolute_value(float x);
long double compute_square_root_of_nonnegative_integer(float N, std::ostream & output);

/**
 * Return the absolute value of a real number input, x.
 */
float absolute_value(float x)
{
    if (x < 0) return -1 * x;
    return x;
}

/**
 * Compute the approximate square root of a real number, x, using Heron's Method.
 * 
 * The square root of x is x raised to the power of 0.5 (i.e. x ^ (1/2)).
 * 
 * Assume that x is a float type value and that output is an output stream object.
 * 
 * This function returns a value whose data type is long double (which is a floating-point number).
 */
long double compute_square_root_of_nonnegative_integer(float x, std::ostream & output)
{
    int i = 0;
    float original_x = x, absolute_value_of_original_x = 0.0;
    long double S = 0.0, Y = 1.0;
    x = absolute_value(x);
    absolute_value_of_original_x = x;
    S = (x > MAXIMUM_X) ? 0 : x; // If x is out of range, then set x to 0.
    output << "\n\nx = " << x << ". // real number to take the square root of";
    output << "\nS = " << S << ". // variable to for storing the approximate square root of x";
    output << "\nY = " << Y << ". // number to add to S before dividing S by 2 for each while loop iteration, i";
    while (S - Y > EPSILON) 
    {
        S = (S + Y) / 2;
        Y = absolute_value_of_original_x / S;
        output << "\n\ni := " << i << ".";
        output << "\nS := ((S + Y) / 2) = " << S << ".";
        output << "\nY := (absolute_value_of_original_x / S) = " << Y << ".";
        i += 1;
    }
    if (original_x < 0) return -1 * S;
    return S;
}

/* program entry point */
int main()
{
    // Declare a float type variable and set its initial value to zero.
    float x = 0.0;

    // Declare a double type variable and set its initial value to zero.
    long double A = 0.0;

    // Declare a file output stream object.
    std::ofstream file;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

    /**
     * If square_root_approximation_output.txt does not already exist in the same directory as square_root_approximation.cpp, 
     * create a new file named square_root_approximation_output.txt.
     * 
     * Open the plain-text file named square_root_approximation_output.txt 
     * and set that file to be overwritten with program data.
     */
    file.open("square_root_approximation_output.txt");

    // Print an opening message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nStart Of Program";
    std::cout << "\n--------------------------------";

    // Print an opening message to the file output stream.
    file << "--------------------------------";
    file << "\nStart Of Program";
    file << "\n--------------------------------";

    // Print "Enter a real number (represented using only base-ten digits and no more than one radix), x, which is no larger than {MAXIMUM_X}: " to the command line terminal.
    std::cout << "\n\nEnter a real number (represented using only base-ten digits and no more than one radix), x, which is no larger than " << MAXIMUM_X << ": ";

    // Scan the command line terminal for the most recent keyboard input value.
    std::cin >> x;

    // Print "The value which was entered for x is {x}." to the command line terminal.
    std::cout << "\nThe value which was entered for x is " << x << ".";

    // Print "The value which was entered for x is {x}." to the file output stream.
    file << "\n\nThe value which was entered for x is " << x << ".";

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "Computing the approximate square root of x:" to the command line terminal.
    std::cout << "\n\nComputing the approximate square root of x:";

    // Print "Computing the approximate square root of x:" to the file output stream.
    file << "\n\nComputing the approximate square root of x:";

    // Compute the approximate square root of x using Heron's Method, print the computational steps to the command line terminal, and store the function result in A.
    A = compute_square_root_of_nonnegative_integer(x, std::cout);

    // Compute the approximate square root of x using Heron's Method and print the computational steps to the file output stream.
    compute_square_root_of_nonnegative_integer(x, file);

    // Print a horizontal line to the command line terminal.
    std::cout << "\n\n--------------------------------";

    // Print a horizontal line to the command line terminal.
    file << "\n\n--------------------------------";

    // Print "A = approximate_square_root({x}) = {A}." to the command line terminal.
    std::cout << "\n\nA = approximate_square_root(" << x << ") = " << A << ".";

    // Print "A = approximate_square_root({x}) = {A}." to the file output stream.
    file << "\n\nA = approximate_square_root(" << x << ") = " << A << ".";

    // Print "(A * A) = " << {(A * A)} << ". // the approximate value of x" to the command line terminal.
    std::cout << "\n\n(A * A) = " << (A * A) << ". // the approximate value of x";

    // Print "(A * A) = " << {(A * A)} << ". // the approximate value of x" to the file output stream.
    file << "\n\n(A * A) = " << (A * A) << ". // the approximate value of x";

    // Print a closing message to the command line terminal.
    std::cout << "\n\n--------------------------------";
    std::cout << "\nEnd Of Program";
    std::cout << "\n--------------------------------\n\n";

    // Print a closing message to the file output stream.
    file << "\n\n--------------------------------";
    file << "\nEnd Of Program";
    file << "\n--------------------------------";

    // Close the file output stream.
    file.close();

    // Exit the program.
    return 0;
}