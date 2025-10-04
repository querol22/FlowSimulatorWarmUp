#pragma once

class Pipe {
public:
    Pipe(double length, double diameter, double viscosity);
    double computeResistance() const;

private:
    double length_;
    double diameter_;
    double viscosity_;
};
