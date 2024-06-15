#ifndef ACCUM_HPP
#define ACCUM_HPP

class Accum{
private:
    float highest_accumulated_value;
    int from_value, to;
public:
    Accum(float highest_accumulated_value, int from_value, int to): highest_accumulated_value(highest_accumulated_value), from_value(from_value), to(to) {}
};

#endif // ACCUM_HPP
