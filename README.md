### Build:

```sh
$ g++ -pthread -std=c++17 -o build/sensornet main.cpp MainNode.cpp Sensor.cpp
```

### Run:

```sh
$ ./build/sensornet [buffor size]
```


In this moment reading from sensors is simulated by reading from text files.
There are two files provided: temperature and speed - it could be configured to N sensors 
and using vectors instead of two values' structure.

To do: add a client thread receiving notifications about the new messsages.
