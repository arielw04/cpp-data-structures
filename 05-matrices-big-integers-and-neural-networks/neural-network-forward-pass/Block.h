#ifndef BLOCK_H
#define BLOCK_H

#include "LinearLayer.h"
#include "ReLUActivation.h"
#include <vector>
using namespace std;

class Block {
private:
    // linear transformation
    LinearLayer linear;

    // activation
    ReLUActivation relu;

public:
    Block(int in_size = 1, int out_size = 1);

    // linear -> relu
    vector<double> forward(const vector<double>& input) const;

    // print both parts
    void display() const;

    // print size
    void size() const;

    // set linear weights
    void setWeights(const vector<double>& flatWeights);

    // set relu slopes
    void setActivationWeights(const vector<double>& actWeights);
};

#endif
