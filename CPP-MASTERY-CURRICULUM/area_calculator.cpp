#include <iostream>
#include <stdexcept>
#include <string>

// Read width and height, compute area of a rectangle. Then extend to compute
// perimeter.

// Q.A.: What happens if the user enters negative numbers? Should your
// program handle this?

constexpr char ENDLINE = '\n';

using RectDim = std::pair<double, double>;

class Rectangle {
public:
  explicit Rectangle(const RectDim &dim) {
    if (dim.first < 0) {
      throw std::invalid_argument("Invalid rectangle width: " +
                                  std::to_string(dim.first));
    }

    if (dim.second < 0) {
      throw std::invalid_argument("Invalid rectangle height: " +
                                  std::to_string(dim.second));
    }

    width = dim.first;
    height = dim.second;
  };

  [[nodiscard]] double rectangle_area() const;
  [[nodiscard]] double rectangle_perimeter() const;
  void print() const;

private:
  double width;
  double height;
};

double Rectangle::rectangle_area() const { return width * height; };
double Rectangle::rectangle_perimeter() const { return 2 * (width + height); };
void Rectangle::print() const {
  std::cout << "================ Rectangle Properties =============="
            << ENDLINE;
  std::cout << "Width: " << width << ENDLINE;
  std::cout << "Height: " << height << ENDLINE;
  std::cout << "Area: " << rectangle_area() << ENDLINE;
  std::cout << "Perimeter: " << rectangle_perimeter() << ENDLINE;
  std::cout << "===================================================="
            << ENDLINE;
}

int main() {
  try {
    double width = 0;
    double height = 0;

    std::cout << "Rectangle Width: ";
    if (!(std::cin >> width)) {
      throw std::invalid_argument(
          "Invalid input. Please enter a numeric width value.");
    }

    std::cout << "Rectangle Height: ";
    if (!(std::cin >> height)) {
      throw std::invalid_argument(
          "Invalid input. Please enter a numeric height value.");
    }

    Rectangle r(RectDim(width, height));
    r.print();

  } catch (const std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
  } catch (...) {
    std::cerr << "An unexpected error has occurred." << ENDLINE;
  }

  return 0;
}
