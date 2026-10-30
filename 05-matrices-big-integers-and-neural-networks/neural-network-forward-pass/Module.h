#ifndef MODULE_H
#define MODULE_H

#include <vector>
using namespace std;

class Module {
protected:
    // flat weight vector
    vector<double> weights;

public:
    // default constructor
    Module();

    virtual ~Module() = default;

    // element-wise multiply forward
    virtual vector<double> forward(const vector<double>& input) const;
};

#endif