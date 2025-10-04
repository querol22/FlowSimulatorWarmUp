#pragma once
#include "pipe.h"

class Flow {
public:
    Flow(double pressure_in, double pressure_out, const Pipe& pipe);
    double computeFlowRate() const;

private:
    double pressure_in_;
    double pressure_out_;
    Pipe pipe_;
};
