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
public:
    std::map<int, float>airq;
    std::map<int, float>uvrad;
    std::map<int, float>traff;
    
    Accum calculate(std::map<int,float>mp){
        auto it = mp.begin();
        float current_max = it->second;
        float global_max = it->second;
        int start = 0, end = 0, temp_start = 0;
        
        for (auto ite = it++; ite != mp.end(); ite++) {
            if (ite->second > current_max + ite->second) {
                current_max = ite->second;
                temp_start = ite->first;
            } else {
                current_max += ite->second;
            }
            
            if (current_max > global_max) {
                global_max = current_max;
                start = temp_start;
                end = ite->first;
            }
        }

        Accum highest(global_max, start, end);
        return highest;
    }
    
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
            return calculate(airq);
        } else if (type_of == "ULTRAVIOLETRADIATION") {
            if (uvrad.size() == 0) return Accum(-1, -1 ,-1);
            return calculate(uvrad);
        } else if (type_of == "TRAFFIC"){
            if (traff.size() == 0) return Accum(-1, -1 ,-1);
            return calculate(traff);
        }
        return Accum(-1, -1 ,-1);
    }
};

void add_sensor(Sensor sensor);
Accum highest_accumulated(std::string type_of);


#endif // SENSOR_HPP