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
    example.add_sensor(sensor)
    return sensor

@app.put("/register_many", response_model = List[Sensor])
async def register_many(sensor_list: List[Sensor]):
    for sensor in sensor_list:
        example.add_sensor(sensor)
    return sensor_list

@app.get("/highest_accumulated", response_model = Accum)
def highest_accumulated(type_of: str):
    return example.highest_accumulated(type_of)


if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="127.0.0.1", port=8000)