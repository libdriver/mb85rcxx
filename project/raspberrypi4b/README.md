### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(mb85rcxx REQUIRED)
```

### 3. MB85RCXX

#### 3.1 Command Instruction

1. Show mb85rcxx chip and driver information.

   ```shell
   mb85rcxx (-i | --information)
   ```

2. Show mb85rcxx help.

   ```shell
   mb85rcxx (-h | --help)
   ```

3. Show mb85rcxx pin connections of the current board.

   ```shell
   mb85rcxx (-p | --port)
   ```

4. Run mb85rcxx read test.

   ```shell
   mb85rcxx (-t read | --test=read) [--type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 | MB85RC256 | MB85RC512 | MB85RC1M>] [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>]
   ```

5. Run mb85rcxx read function, reg is the register address and it is hexadecimal.

   ```shell
   mb85rcxx (-e read | --example=read) [--type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 | MB85RC256 | MB85RC512 | MB85RC1M>] [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--reg=<address>]
   ```

6. Run mb85rcxx write function, reg is the register address and data is the set value, both are hexadecimal.

   ```shell
   mb85rcxx (-e write | --example=write) [--type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 | MB85RC256 | MB85RC512 | MB85RC1M>] [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--reg=<address>] [--data=<value>]
   ```

#### 3.2 Command Example

```shell
./mb85rcxx -i

mb85rcxx: chip is RAMXEED MB85RCXX.
mb85rcxx: manufacturer is RAMXEED.
mb85rcxx: interface is IIC.
mb85rcxx: driver version is 1.0.
mb85rcxx: min supply voltage is 1.7V.
mb85rcxx: max supply voltage is 5.5V.
mb85rcxx: max current is 0.02mA.
mb85rcxx: max temperature is 85.0C.
mb85rcxx: min temperature is -40.0C.
```

```shell
./mb85rcxx -p

mb85rcxx: SCL connected to GPIO3(BCM).
mb85rcxx: SDA connected to GPIO2(BCM).
```

```shell
./mb85rcxx -t read --type=MB85RC64 --addr=0

mb85rcxx: chip is RAMXEED MB85RCXX.
mb85rcxx: manufacturer is RAMXEED.
mb85rcxx: interface is IIC.
mb85rcxx: driver version is 1.0.
mb85rcxx: min supply voltage is 1.7V.
mb85rcxx: max supply voltage is 5.5V.
mb85rcxx: max current is 0.02mA.
mb85rcxx: max temperature is 85.0C.
mb85rcxx: min temperature is -40.0C.
mb85rcxx: start read test.
mb85rcxx: 0x0000 read write test passed.
mb85rcxx: 0x0100 read write test passed.
mb85rcxx: 0x0200 read write test passed.
mb85rcxx: 0x0300 read write test passed.
mb85rcxx: 0x0400 read write test passed.
mb85rcxx: 0x0500 read write test passed.
mb85rcxx: 0x0600 read write test passed.
mb85rcxx: 0x0700 read write test passed.
mb85rcxx: finish read test.
```

```shell
./mb85rcxx -e read --type=MB85RC64 --addr=0 --reg=0001

mb85rcxx: read 0x0001 is 0x11.
```

```shell
./mb85rcxx -e write --type=MB85RC64 --addr=0 --reg=0001 --data=15

mb85rcxx: write 0x0001 is 0x11.
```

```shell
./mb85rcxx -h

Usage:
  mb85rcxx (-i | --information)
  mb85rcxx (-h | --help)
  mb85rcxx (-p | --port)
  mb85rcxx (-t read | --test=read) [--type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 |
                                            MB85RC256 | MB85RC512 | MB85RC1M>]
          [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>]
  mb85rcxx (-e read | --example=read) [--type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 |
                                               MB85RC256 | MB85RC512 | MB85RC1M>]
          [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--reg=<address>]
  mb85rcxx (-e write | --example=write) [--type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 |
                                                 MB85RC256 | MB85RC512 | MB85RC1M>]
          [--addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>] [--reg=<address>] [--data=<value>]

Options:
      --addr=<0 | 1 | 2 | 3 | 4 | 5 | 6 | 7>    Set the connection of the addr pin and the addr number is A2A1A0.([default: 0])
      --data=<value>                            Set the sent data and it is hexadecimal.([default: random])
  -e <read>, --example=<read>                   Run the driver example.
  -h, --help                                    Show the help.
  -i, --information                             Show the chip information.
  -p, --port                                    Display the pin connections of the current board.
      --reg=<address>                           Set the register address and it is hexadecimal.([default: 0x0000])
  -t <read | write>, --test=<read | write>      Run the driver test.
      --type=<MB85RC04 | MB85RC16 | MB85RC64 | MB85RC128 |
              MB85RC256 | MB85RC512 | MB85RC1M>
                                                Set the chip type.([default: MB85RC16])
```
