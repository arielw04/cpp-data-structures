#include "Block.h"

// initialize block
Block::Block(int in_size, int out_size)
    : linear(in_size, out_size), relu() {
}

// forward pass
vector<double> Block::forward(const vector<double>& input) const {
    // linear layer
    vector<double> linearOutput = linear.forward(input);

    // activation
    return relu.forward(linearOutput);
}

// display contents
void Block::display() const {
    linear.display();
    relu.display();
}

// print size
void Block::size() const {
    linear.size();
}

// set linear weights
void Block::setWeights(const vector<double>& flatWeights) {
    linear.setFlatWeights(flatWeights);
}

// set activation weights
void Block::setActivationWeights(const vector<double>& actWeights) {
    relu.setWeights(actWeights);
}