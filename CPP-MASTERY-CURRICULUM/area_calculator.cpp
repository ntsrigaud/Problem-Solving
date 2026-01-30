#include <iostream>
#include <stdexcept>
#include <string>

// Read width and height, compute area of a rectangle. Then extend to compute
// perimeter. Q.A.: What happens if the user enter negative numbers? Should your
// program handle this?

constexpr char ENDLINE = '\n';

extern double rectangle_area(double w, double h);

int main() {
  try {
    double width = 0;
    double height = 0;

    std::cout << "Rectangle Width: ";
    if (!(std::cin >> width)) {
      throw std::invalid_argument(
          "Invalid input. Please enter a numeric width value.");
      ;
    }

    std::cout << "Rectangle Height: ";
    if (!(std::cin >> height)) {
      throw std::invalid_argument(
          "Invalid input. Please enter a numeric height value.");
    }

    double rect_area = rectangle_area(width, height);

    std::cout << "Rectangle area: " << rect_area << ENDLINE;

  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << "\n";
  } catch (...) {
    std::cerr << "An unexpected error has occurred." << ENDLINE;
  }

  return 0;
}

double rectangle_area(double w, double h) {
  if (w < 0) {
    throw std::invalid_argument("Invalid rectangle width: " +
                                std::to_string(w));
  }

  if (h < 0) {
    throw std::invalid_argument("Invalid rectangle height: " +
                                std::to_string(h));
  }

  return w * h;
}
