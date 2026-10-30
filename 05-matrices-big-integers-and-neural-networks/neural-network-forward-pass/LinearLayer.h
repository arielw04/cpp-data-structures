#ifndef LINEARLAYER_H
#define LINEARLAYER_H

#include "Module.h"
#include <vector>
#include <iostream>
using namespace std;

class LinearLayer : public Module {
private:
    // number of inputs
    int input_size;

    // number of outputs
    int output_size;

    // bias vector
    vector<double> bias;

public:
    LinearLayer(int in_size = 1, int out_size = 1);

    // W*x + b
    vector<double> forward(const vector<double>& input) const override;

    // print weights/bias
    void display() const;

    // print dimensions
    void size() const;

    // set weights
    void setFlatWeights(const vector<double>& newWeights);
};

#endif