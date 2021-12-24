// MatPlotPlusPlus Test / Example

/*
Testing to see if MatPlotPlusPlus works.
	- Line plot example.
*/


// C++ Includes:
#include <iostream>
#include <cmath>
#include <vector>

// Matplot++ Includes:
#include <matplot/matplot.h>


int main() {
	using namespace matplot;

    // x-axis | matplot::linspace() and std::pi (from cmath)
    std::vector<double> x = linspace(0, 2 * pi);
    // y-axis | matplot::transform() and std::sin() (from cmath)
    std::vector<double> y1 = transform(x, [](auto x) { return sin(x); });
    
    // plot the graph | matplot::plot()
    plot(x, y1);

    // we can save the image by using the save() function
    save("test_image.png");

    // show the plot when we run the program | matplot::show()
    show();

	return 0;
}
