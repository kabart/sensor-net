### Buildng:

```sh
$ make target
```

### Run:

```sh
$ ./build/sensornet [buffor size]
```

### Buildng tests:

```sh
$ make test
```

### Run:

```sh
$ ./build-test/runTests
```

### Buildng both the executable and tests:

```sh
$ make all
```

In this moment reading from sensors is simulated by reading from text files.
There are two files provided: temperature and speed - it could be configured to N sensors 
and using vectors instead of two values' structure.

To do: add a client thread receiving notifications about the new messsages.
