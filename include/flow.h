#pragma once
#include "pipe.h"
#include <vector>

class Flow {
public:
    // For a single Pipe:  
    // Flow(double pressure_in, double pressure_out, const Pipe& pipe);
    // double computeFlowRate() const;
    
    // Extended version for pipe diversification through series & parallel resistor equivalents:
    Flow(double pressure_in, double pressure_out);
    double computeFlowRateSeries(const std::vector<Pipe>& pipes);
    double computeFlowRateParallel(const std::vector<Pipe>& pipes);

private:
    double pressure_in;
    double pressure_out;
    //Pipe pipe;
};
