/**
 * This sample program balances a two-wheeled Segway type robot such as Gyroboy in EV3 core set.
 *
 * References:
 * http://www.hitechnic.com/blog/gyro-sensor/htway/
 * http://www.cs.bgu.ac.il/~ami/teaching/Lejos-2013/classes/src/lejos/robotics/navigation/Segoway.java
 */

#include "ev3api.h"
#include "app.h"

#include "libcpp-test.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

class TestClass {

public:
    TestClass()
    {
        while (1){
            label:
                member = 1;
                ev3_motor_config(EV3_PORT_B, LARGE_MOTOR);
                int32_t backMotorCount = ev3_motor_get_counts(EV3_PORT_B);
                int32_t bIteration = -550;
                while (backMotorCount >= bIteration) {
                    ev3_motor_set_power(EV3_PORT_B, (int)-20);
                    backMotorCount = ev3_motor_get_counts(EV3_PORT_B);
                    ev3_motor_set_power(EV3_PORT_B, (int)0);
                    bIteration = bIteration - 550;
                }
            label2:
                member = 2;
                ev3_motor_config(EV3_PORT_C, LARGE_MOTOR);
                int32_t frontMotorCount = ev3_motor_get_counts(EV3_PORT_C);
                int32_t fIteration = -110;
                while (frontMotorCount >= fIteration) {
                    ev3_motor_set_power(EV3_PORT_C, (int)-20);
                    frontMotorCount = ev3_motor_get_counts(EV3_PORT_C);
                    ev3_motor_set_power(EV3_PORT_C, (int)0);
                    fIteration = fIteration - 110;
                }
                goto label2;
        }
    }

    void testMethod()
    {
        static char buf[256];
        sprintf(buf, "Task Running is :  0x%08x.", member);
        ev3_lcd_draw_string(buf, 0, 32);
    }

private:
    int member;
};

auto obj2 = new TestClass();

void main_task(intptr_t unused)
{
    // Test global constructor
    obj2->testMethod();

}
