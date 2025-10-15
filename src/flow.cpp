#include "flow.h"
#include <cmath>

    // For a single Pipe:  
    // Flow::Flow(double pressure_in, double pressure_out, const Pipe& pipe): pressure_in_(pressure_in), pressure_out_(pressure_out), pipe_(pipe) {}
    // double Flow::computeFlowRate() const {
    // double resistance = pipe_.computeResistance();
    // return (pressure_in_ - pressure_out_) / resistance;
    // }

// Extended version for pipe diversification through series & parallel resistor equivalents:
Flow::Flow(double pressure_in, double pressure_out) : pressure_in(pressure_in), pressure_out(pressure_out) {}

double Flow::computeFlowRateSeries(const std::vector<Pipe>& pipes) {
    double totalResistance = 0.0;
    for (const auto& onePipe : pipes)
        totalResistance += onePipe.computeResistance();
    return (pressure_in - pressure_out) / totalResistance;
}

double Flow::computeFlowRateParallel(const std::vector<Pipe>& pipes) {
    double invResistanceSum = 0.0;
    for (const auto& onePipe : pipes)
        invResistanceSum += 1.0 / onePipe.computeResistance();
    double totalResistance = 1.0 / invResistanceSum;
    return (pressure_in - pressure_out) / totalResistance;
}