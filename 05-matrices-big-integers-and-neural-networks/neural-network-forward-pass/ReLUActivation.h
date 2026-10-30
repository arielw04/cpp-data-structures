#ifndef RELUACTIVATION_H
#define RELUACTIVATION_H

#include "Module.h"
#include <vector>
#include <iostream>
using namespace std;

class ReLUActivation : public Module {
public:
    // slopes for positive/negative
    ReLUActivation(double p_s = 1.0, double n_s = 0.0);

    // apply ReLU
    vector<double> forward(const vector<double>& input) const override;

    // print slopes
    void display() const;

    // set slopes
    void setWeights(const vector<double>& newWeights);
};

#endif