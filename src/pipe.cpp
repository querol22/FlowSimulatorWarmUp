#include "pipe.h"
#include <cmath>

Pipe::Pipe(double length, double diameter, double viscosity)
    : length_(length), diameter_(diameter), viscosity_(viscosity) {}

double Pipe::computeResistance() const {
    // Hagen-Poiseuille law: R = (8 * μ * L) / (π * r^4)
    double radius = diameter_ / 2.0;
    return (8.0 * viscosity_ * length_) / (M_PI * std::pow(radius, 4));
}
