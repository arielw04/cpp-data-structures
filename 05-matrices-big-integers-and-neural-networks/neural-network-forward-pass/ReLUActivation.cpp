#include "ReLUActivation.h"

// initialize slopes
ReLUActivation::ReLUActivation(double p_s, double n_s) {
    // positive slope
    weights.push_back(p_s);

    // negative slope
    weights.push_back(n_s);
}

vector<double> ReLUActivation::forward(const vector<double>& input) const {
    vector<double> output(input.size(), 0.0);

    double positiveSlope = 1.0;
    double negativeSlope = 0.0;

    if (!weights.empty()) {
        positiveSlope = weights[0];
    }

    if (weights.size() > 1) {
        negativeSlope = weights[1];
    }

    for (size_t i = 0; i < input.size(); i++) {
        // positive case
        if (input[i] >= 0) {
            output[i] = positiveSlope * input[i];
        }
        // negative case
        else {
            output[i] = negativeSlope * input[i];
        }
    }

    return output;
}

void ReLUActivation::display() const {
    double positiveSlope = 1.0;
    double negativeSlope = 0.0;

    if (!weights.empty()) {
        positiveSlope = weights[0];
    }

    if (weights.size() > 1) {
        negativeSlope = weights[1];
    }

    cout << "ReLUActivation: slope = " << positiveSlope
        << ", negative slope = " << negativeSlope << endl;
}

// update slopes
void ReLUActivation::setWeights(const vector<double>& newWeights) {
    weights = newWeights;
}