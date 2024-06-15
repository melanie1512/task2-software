#include "sensor.hpp"

// Create a global instance of SensorManager
SensorManager sensor_manager;

void add_sensor(Sensor sensor) {
    sensor_manager.add(sensor);
    return;
}

Accum highest_accumulated(std::string type_of) {
    return sensor_manager.get_highest_accumulated(type_of);
}
