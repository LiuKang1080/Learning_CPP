// Test Script

#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

#include <sciplot/sciplot.hpp>


int main() {
    //using namespace boost::multiprecision;

    //// create variable to store very large number from the boost::multipercision library
    //cpp_int num = 1;

    //// use for loop to get the result of 100!
    //for (unsigned int i = 1; i <= 100; i++) {
    //    num *= i;
    //}

    //std::cout << num << "\n";

    // Sciplot:
    using namespace sciplot;
    // Create values for your x-axis
    Vec x = linspace(0.0, 5.0, 100);

    // Create a Plot object
    Plot plot;

    // Set color palette
    plot.palette("set2");

    // Draw a sine graph putting x on the x-axis and sin(x) on the y-axis
    plot.drawCurve(x, std::sin(x)).label("sin(x)").lineWidth(1);

    // Draw a cosine graph putting x on the x-axis and cos(x) on the y-axis
    plot.drawCurve(x, std::cos(x)).label("cos(x)").lineWidth(1);

    // Show the plot in a pop-up window
    plot.show();

    // Save the plot to a PDF file
    plot.save("plot_1.pdf");

    return 0;
}
