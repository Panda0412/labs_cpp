#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

float function(float x) {
    return -x * log(x);
}

int main() {
    int width, height;
    float x0, x1, f_min = 0, f_max = 0;
    cin >> width >> height >> x0 >> x1;

    // Width of one cell
    float cell_w = (x1 - x0) / width;

    // Array with function values
    auto *values = new float[width];
    for (int i = 0; i < width; i++) {
        float x = x0 + cell_w * i;
        float y = function(x);

        values[i] = y;

        // Search min and max function value
        f_min = fmin(y, f_min);
        f_max = fmax(y, f_max);
    }

    // Height of one cell
    float cell_h = (f_max - f_min) / height;

    // Number of cells for each function value
    for (int i = 0; i < width; i++) {
        values[i] = round(values[i] / cell_h);
    }

    // Axis line number
    int axis = ceil(f_max / cell_h);

    // File with result
    ofstream output_file ("ex1.txt");
    // Graph drawing
    for (int i = 1; i <= height+1; i++) {
        if (i < axis) {                      // Positive function values
            for (int j = 0; j < width; j++) {
                if ((axis - i) <= values[j]) { output_file << '#'; }
                else { output_file << ' '; }
            }
        } else if (i > axis) {               // Negative function values
            for (int j = 0; j < width; j++) {
                if ((i - axis) <= (- values[j])) { output_file << '#'; }
                else { output_file << ' '; }
            }
        } else {                             // Axis
            for (int j = 0; j < width; ++j) {
                output_file << '-';
            }
        }
        output_file << endl;
    }

    delete[] values;

    return 0;
}
