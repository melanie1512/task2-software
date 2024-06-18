import example
from fastapi import FastAPI, HTTPException, Query
from typing import List, Optional
from pydantic import BaseModel

app = FastAPI()

class Sensor(BaseModel):
    timestamp: int
    type_of_sensor: str
    read: float

class Accum(BaseModel):
    highest_accumulated_value: float
    from_value: int
    to: int

@app.put("/register_one", response_model = Sensor)
async def register_one(sensor: Sensor):
    sensor_cpp = example.Sensor(sensor.timestamp, sensor.type_of_sensor, sensor.read)
    example.add_sensor(sensor_cpp)
    return sensor

@app.put("/register_many", response_model = List[Sensor])
async def register_many(sensor_list: List[Sensor]):
    for sensor in sensor_list:
        sensor_cpp = example.Sensor(sensor.timestamp, sensor.type_of_sensor, sensor.read)
        example.add_sensor(sensor_cpp)
    return sensor_list

@app.get("/highest_accumulated", response_model = Accum)
def highest_accumulated(type_of: str):
    accum_cpp = example.highest_accumulated(type_of)
    ans = Accum(
            highest_accumulated_value=accum_cpp.get_highest_accumulated_value(),
            from_value=accum_cpp.get_from_value(),
            to=accum_cpp.get_to()
        )
    return ans


if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="127.0.0.1", port=8000)