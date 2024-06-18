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
    
    Accum calculate(std::map<int,float>mp){
        std::vector<float>dp(mp.size(), 0);
        std::vector<int> start_indices(mp.size(), 0);

        dp[0] = mp.begin()->second;
        start_indices[0] = mp.begin()->first;

        float ans = dp[0];
        int i = 1; 

        int best_start = mp.begin()->first, best_end = mp.begin()->first;
        int current_start = mp.begin()->first;
        for (auto ele: mp) {
            if (ele.second > ele.second + dp[i - 1]){
                dp[i] = ele.second;
                current_start = ele.first;
            }

            start_indices[i] = current_start;

            if (dp[i] > ans) {
                ans = dp[i];
                best_start = start_indices[i];
                best_end = ele.first;
            }
            i++;
        }
        Accum highest(ans, best_start, best_end);
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