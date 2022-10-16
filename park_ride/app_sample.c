#include "app.h"
#include "auto_ride.h"

typedef enum {
  AR_INIT,
  AR_WAIT_FOR_LOADING, AR_TRANSPORTING, AR_ARRIVED
} auto_ride_state;

auto_ride_state ar_state = AR_INIT;
int ar_entry = true;

void auto_ride_config(void) {
    unit_a_config();
}

void auto_ride_XXXXt(void) {
  num_f(ar_state, 2);
  switch(ar_state) {
  case AR_INIT:
    ar_config();
    ar_state = AR_WAIT_FOR_LOADING;
    break;
  case AR_WAIT_FOR_LOADING:
    if( ar_entry ) {
      ar_entry = false;
    }
    unit_a_do_act();
    if(unit_a_is_seated()) {
      ar_state = AR_TRANSPORTING;
      ar_entry = true;
    }
    if( ar_entry ) {
      // exit action
    }
    break;
  case AR_TRANSPORTING:
    break;
  case AR_ARRIVED:
    break;
  default:
    break;
  }
}

void main_task(intptr_t unused) {
  /*
    これらは、徐々に各ユニットのconfig関数へ移し、
    それぞれのユニットのINIT状態でconfigを呼び出す
  static int is_initialized = false;
    if(! is_initialized ) {
    is_initialized = true;
    init_f("park_ride");
    ev3_motor_config(left_motor, LARGE_MOTOR);
    ev3_motor_config(right_motor, LARGE_MOTOR);
    ev3_sensor_config(walldetector_sensor, ULTRASONIC_SENSOR); // <1>
    ev3_sensor_config(linemon_sensor, COLOR_SENSOR);
    ev3_sensor_config(bumper_sensor, TOUCH_SENSOR);
    ev3_sensor_config(carrier_sensor, TOUCH_SENSOR); // <2>
  }
  */
  auto_ride_XXXX();
  ext_tsk();
}
