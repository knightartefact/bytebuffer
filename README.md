# Bytebuffer

A simple byte buffer library in **C** with basic functionnality

## Building

Simply run the following commands in your terminal:
```
$> mkdir build && cd build
$> cmake ..
$> make
```

The actual configuration only builds a static library for the moment.

## Unit testing

The project also contains unit tests written with the **criterion** library.

To run the tests run the following binary in the ***build*** directory after building:
```
./tests/bytebuffer_tests
```
