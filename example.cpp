#include <iostream>
#include <pybind11/pybind11.h>
#include "sensor.hpp"

namespace py = pybind11;

PYBIND11_MODULE(example, m){
    py::class_<Sensor>(m, "Sensor")
        .def(py::init<int, std::string, float>())
        .def("get_timestamp", &Sensor::get_timestamp)
        .def("get_type_of_sensor", &Sensor::get_type_of_sensor)
        .def("get_read", &Sensor::get_read);

    py::class_<Accum>(m, "Accum")
        .def(py::init<float, int, int>())
        .def("get_highest_accumulated_value", &Accum::get_highest_accumulated_value)
        .def("get_from_value", &Accum::get_from_value)
        .def("get_to", &Accum::get_to);

    py::class_<SensorManager>(m, "SensorManager")
        .def(py::init<>())
        .def("add", &SensorManager::add)
        .def("get_highest_accumulated", &SensorManager::get_highest_accumulated);

    m.def("add_sensor", &add_sensor);
    m.def("highest_accumulated", &highest_accumulated);
}