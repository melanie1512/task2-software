#include "sensor.cpp"
#include <iostream>

int main(){
    SensorManager Manager;

    Sensor a1(0,"AIRQUALITY", -2.5);
    Sensor a2(1,"AIRQUALITY", 1.5);
    Sensor a3(2,"AIRQUALITY", -0.5);
    Sensor a4(3,"AIRQUALITY", 4);
    Sensor a5(4,"AIRQUALITY", -1);
    Sensor a6(5,"AIRQUALITY", 2);
    Sensor a7(6,"AIRQUALITY", 1.5);
    Sensor a8(7,"AIRQUALITY", -5.5);
    Sensor a9(7,"AIRQUALITY", 3);

    Manager.add(a1);
    Manager.add(a2);
    Manager.add(a3);
    Manager.add(a4);
    Manager.add(a5);
    Manager.add(a6);
    Manager.add(a7);
    Manager.add(a8);
    Manager.add(a9);
    
    auto result = Manager.get_highest_accumulated("AIRQUALITY");

    std::cout << result.get_highest_accumulated_value() << std::endl;
    std::cout << result.get_from_value() << std::endl;
    std::cout << result.get_to() << std::endl;
}