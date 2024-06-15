#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "accum.hpp"

class Sensor{
private:
    int timestamp;
    std::string type_of_sensor;
    float read;
public:
    Sensor(int timestamp, std::string type_of_sensor, float read): timestamp(timestamp), type_of_sensor(type_of_sensor), read(read) {};

    int get_timestamp(){
        return this->timestamp;
    }
    std::string get_type_of_sensor(){
        return this->type_of_sensor;
    }
    float get_read(){
        return this->read;
    }
};

class SensorManager{
private:
    std::map<int, float>airq;
    std::map<int, float>uvrad;
    std::map<int, float>traff;
public:
    SensorManager(){};

    void add(Sensor sensor){
        std::string type = sensor.get_type_of_sensor();

        if (type == "AIRQUALITY"){
            airq.insert({sensor.get_timestamp(), sensor.get_read()});
            return;
        }
        else if (type == "ULTRAVIOLETRADIATION"){
            uvrad.insert({sensor.get_timestamp(), sensor.get_read()});
            return;
        }
        else if (type == "TRAFFIC"){
            traff.insert({sensor.get_timestamp(), sensor.get_read()});
            return;
        }
        std::cout << "NO TYPE" << std::endl;
        return;
    }

    Accum get_highest_accumulated(std::string type_of){
        if (type_of == "AIRQUALITY"){
            if (airq.size() == 0) return Accum(-1, -1 ,-1);
            return Accum(airq.begin()->first, airq.begin()->second, airq.begin()->second);
        } else if (type_of == "ULTRAVIOLETRADIATION") {
            if (uvrad.size() == 0) return Accum(-1, -1 ,-1);
            return Accum(uvrad.begin()->first, uvrad.begin()->second, uvrad.begin()->second);
        } else if (type_of == "TRAFFIC"){
            if (traff.size() == 0) return Accum(-1, -1 ,-1);
            return Accum(traff.begin()->first, traff.begin()->second, traff.begin()->second);
        }
        return Accum(-1, -1 ,-1);
    }
};

void add_sensor(Sensor sensor);
Accum highest_accumulated(std::string type_of);


#endif // SENSOR_HPP