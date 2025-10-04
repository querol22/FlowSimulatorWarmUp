#include "flow.h"

Flow::Flow(double pressure_in, double pressure_out, const Pipe& pipe)
    : pressure_in_(pressure_in), pressure_out_(pressure_out), pipe_(pipe) {}

double Flow::computeFlowRate() const {
    double resistance = pipe_.computeResistance();
    return (pressure_in_ - pressure_out_) / resistance;
}
