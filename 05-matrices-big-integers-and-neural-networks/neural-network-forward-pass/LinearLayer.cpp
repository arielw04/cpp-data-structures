#include "LinearLayer.h"

// initialize sizes and bias
LinearLayer::LinearLayer(int in_size, int out_size)
    : input_size(in_size), output_size(out_size), bias(out_size, 1.0) {

    // initialize weights to 1
    weights.resize(input_size * output_size, 1.0);
}

vector<double> LinearLayer::forward(const vector<double>& input) const {
    vector<double> output(output_size, 0.0);

    for (int i = 0; i < output_size; i++) {
        double sum = 0.0;

        for (int j = 0; j < input_size; j++) {
            // row-major indexing
            sum += weights[i * input_size + j] * input[j];
        }

        // add bias
        output[i] = sum + bias[i];
    }

    return output;
}

void LinearLayer::display() const {
    cout << "LinearLayer expected weight dimensions: "
        << input_size << " (input) x " << output_size << " (output)" << endl;

    cout << "Bias:";
    for (double b : bias) {
        cout << " " << b;
    }
    cout << endl;

    cout << "Flat weight vector:";
    for (double w : weights) {
        cout << " " << w;
    }
    cout << endl;
}

void LinearLayer::size() const {
    cout << "LinearLayer - Input size: " << input_size
        << ", Output size: " << output_size << endl;
}

// replace weights
void LinearLayer::setFlatWeights(const vector<double>& newWeights) {
    weights = newWeights;
}