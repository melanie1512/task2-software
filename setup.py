from setuptools import setup, Extension
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "example",
        ["sensor.cpp", "example.cpp"],
        extra_compile_args=["-std=c++11"]
    )
]

setup(
    name="example",
    version="1.0",
    author="Melanie",
    description="Prueba",
    ext_modules=ext_modules,
    cmdclass={"build ext": build_ext},
)