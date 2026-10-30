#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Block.h"
#include <vector>
#include <iostream>
using namespace std;

class NeuralNetwork {
private:
    // list of blocks
    vector<Block> blocks;

public:
    NeuralNetwork(int num_blocks, int in_size, int hidden_size, int out_size);

    // full forward pass
    vector<double> forward(const vector<double>& input) const;

    // print details
    void printModel() const;

    // print sizes
    void printBlockSizes() const;

    void setBlockWeights(int block_index, const vector<double>& flatWeights);
    void setBlockActivationWeights(int block_index, const vector<double>& actWeights);
};

#endif