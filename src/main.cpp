#include <iostream>
#include "pipe.h"
#include "flow.h"

int main() {
    // Parameters
    double length = 0.1;        // meters
    double diameter = 0.01;     // meters
    double viscosity = 0.004;   // Pa·s (blood-like)
    double pin = 13332.0;       // 100 mmHg in Pascals
    double pout = 8000.0;       // 60 mmHg in Pascals

    Pipe pipe(length, diameter, viscosity);
    Flow flow(pin, pout, pipe);

    double flowRate_m3s = flow.computeFlowRate();
    double flowRate_Lmin = flowRate_m3s * 60000.0;  // convert to L/min

    std::cout << "Flow rate: " << flowRate_m3s << " m³/s" << std::endl;
    std::cout << "Flow rate: " << flowRate_Lmin << " L/min" << std::endl;

    return 0;
}
