#include "NeuralNetwork.h"

// build network structure
NeuralNetwork::NeuralNetwork(int num_blocks, int in_size, int hidden_size, int out_size) {

    // single block case
    if (num_blocks < 2) {
        blocks.push_back(Block(in_size, out_size));
    }
    else {
        // first block
        blocks.push_back(Block(in_size, hidden_size));

        // middle blocks
        for (int i = 1; i < num_blocks - 1; i++) {
            blocks.push_back(Block(hidden_size, hidden_size));
        }

        // last block
        blocks.push_back(Block(hidden_size, out_size));
    }
}

// forward through all blocks
vector<double> NeuralNetwork::forward(const vector<double>& input) const {
    vector<double> current = input;

    for (size_t i = 0; i < blocks.size(); i++) {
        current = blocks[i].forward(current);
    }

    return current;
}

// print full model
void NeuralNetwork::printModel() const {
    for (size_t i = 0; i < blocks.size(); i++) {
        cout << "Block " << i + 1 << ":" << endl;
        blocks[i].display();
        cout << "-----------------------------" << endl;
    }
}

// print sizes
void NeuralNetwork::printBlockSizes() const {
    for (size_t i = 0; i < blocks.size(); i++) {
        cout << "Block " << i + 1 << " size: ";
        blocks[i].size();
    }
}

// set weights for a block
void NeuralNetwork::setBlockWeights(int block_index, const vector<double>& flatWeights) {
    if (block_index >= 0 && block_index < (int)blocks.size()) {
        blocks[block_index].setWeights(flatWeights);
    }
}

// set activation weights
void NeuralNetwork::setBlockActivationWeights(int block_index, const vector<double>& actWeights) {
    if (block_index >= 0 && block_index < (int)blocks.size()) {
        blocks[block_index].setActivationWeights(actWeights);
    }
}