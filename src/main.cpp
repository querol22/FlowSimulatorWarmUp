#include <iostream>
#include <vector>
#include "pipe.h"
#include "flow.h"

int main() {
    // Parameters
    double pressure_in = 13332.0;       // 100 mmHg in Pascals
    double pressure_out = 8000.0;       // 60 mmHg in Pascals
        // For a single Pipe:  
        // double length = 0.1;        // meters
        // double diameter = 0.01;     // meters
        // double viscosity = 0.004;   // Pa·s (blood-like)

        // Pipe pipe(length, diameter, viscosity);
        // Flow flow(pressure_in, pressure_out, pipe);

    // Extended version - create two vessels (e.g., afferent & efferent):
    Pipe afferent(0.005, 0.001, 0.004);   // length, diameter, viscosity
    Pipe efferent(0.002, 0.001, 0.004);

    Flow flow(pressure_in, pressure_out);

    // SERIES
    std::vector<Pipe> series = {afferent, efferent};
    double Qseries = flow.computeFlowRateSeries(series);

    // PARALLEL
    std::vector<Pipe> parallel = {afferent, efferent};
    double Qparallel = flow.computeFlowRateParallel(parallel);

    // Unit Conversion & Console Output - For a single Pipe:
        //double flowRate_m3s = flow.computeFlowRate();
        //double flowRate_Lmin = flowRate_m3s * 60000.0;  // convert to L/min
        //std::cout << "Flow rate: " << flowRate_m3s << " m³/s" << std::endl;
        //std::cout << "Flow rate: " << flowRate_Lmin << " L/min" << std::endl;
    
    // Console Output for extended version, with Unit conversion included.
    std::cout << "Flow (series): " << Qseries << " m³/s  = " << Qseries * 60000 << " L/min\n";
    std::cout << "Flow (parallel): " << Qparallel << " m³/s  = " << Qparallel * 60000 << " L/min\n";

    return 0;
}
