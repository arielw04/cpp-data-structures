#include "Module.h"

// default weight = 1.0
Module::Module() : weights(1, 1.0) {
}

vector<double> Module::forward(const vector<double>& input) const {
    vector<double> result(input.size(), 0.0);
    vector<double> effectiveWeights = weights;

    // resize if needed
    if (effectiveWeights.size() != input.size()) {
        effectiveWeights.resize(input.size(), 1.0);
    }

    for (size_t i = 0; i < input.size(); i++) {
        // element-wise multiply
        result[i] = input[i] * effectiveWeights[i];
    }

    return result;
}