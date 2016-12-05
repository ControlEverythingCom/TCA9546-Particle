#include "spark_wiring_i2c.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_constants.h"

class TCA9546{
public:
    bool setAddress(int a0, int a1, int a2);
    bool setPort(int port);
    void scanPort();
private:
    int address = 112;

};