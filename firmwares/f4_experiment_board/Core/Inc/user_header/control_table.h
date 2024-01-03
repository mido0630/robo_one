#ifndef CONTROL_TABLE_H
#define CONTROL_TABLE_H

#include <stdint.h>

//instruction
#define INST_PING 0x01
#define INST_READ 0x02
#define INST_WRITE 0x03
#define INST_REG_WRITE 0x04
#define INST_ACTION 0x05
#define INST_FACTORY_RESET 0x06
#define INST_REBOOT 0x08
#define INST_SYNC_READ 0x82
#define INST_SYNC_WRITE 0x83
#define INST_BULK_READ 0x92
#define INST_BULK_WRITE 0x93

//control table
#define MODEL_NUMBER 0
#define MODEL_INFORMATION 2
#define VERSION_OF_FIRMWARE 6
#define ID 7
#define BAUDRATE 8
#define RETURN_DELAY_TIME 9
#define DRIVE_MODE 10
#define OPERATING_MODE 11
#define SECONDARY_ID 12
#define PROTOCOL_VERSION 13
#define RESERVED_14_19 14
#define HOMING_OFFSET 20
#define MOVING_THRESHOLD 24
#define RESERVED_28_30 28
#define TEMPERATURE_LIMIT 31
#define MAX_VOLTAGE_LIMIT 32
#define MIN_VOLTAGE_LIMIT 34
#define PWM_LIMIT 36
#define CURRENT_LIMIT 38
#define ACCELERATION_LIMIT 40
#define VELOCITY_LIMIT 44
#define MAX_POSITION_LIMIT 48
#define MIN_POSITION_LIMIT 52
#define EXTERNAL_PORT_MODE_1 56
#define EXTERNAL_PORT_MODE_2 57
#define EXTERNAL_PORT_MODE_3 58
#define RESERVED_59_62 59
#define SHUTDOWN 63
#define TORQUE_ENABLE 64
#define LED 65
#define RESERVED_66_67 66
#define STATUS_RETURN_LEVEL 68
#define REGISTERED_INSTRUCTION 69
#define HARDWARE_ERROR_STATUS 70
#define RESERVED_71_75 71
#define VELOCITY_I_GAIN 76
#define VELOCITY_P_GAIN 78
#define POSITION_D_GAIN 80
#define POSITION_I_GAIN 82
#define POSITION_P_GAIN 84
#define RESERVED_86_87 86
#define FEEDFORWARD_ACCELERATION_GAIN 88
#define FEEDFORWARD_VELOCITY_GAIN 90
#define RESERVED_92_97 92
#define BUS_WATCHDOG 98
#define RESERVED_99 99
#define GOAL_PWM 100
#define GOAL_CURRENT 102
#define GOAL_VELOCITY 104
#define PROFILE_ACCELERATION 108
#define PROFILE_VELOCITY 112
#define GOAL_POSITION 116
#define REALTIME_TICK 120
#define MOVING 122
#define MOVING_STATUS 123
#define PRESENT_PWM 124
#define PRESENT_CURRENT 126
#define PRESENT_VELOCITY 128
#define PRESENT_POSITION 132
#define VELOCITY_TRAJECTORY 136
#define POSITION_TRAJECTORY 140
#define PRESENT_INPUT_VOLTAGE 144
#define PRESENT_TEMPERATURE 146

typedef struct {
    uint16_t model_number;               // 0
    uint32_t model_information;          // 2
    uint8_t version_of_firmware;         // 6
    uint8_t id;                          // 7
    uint8_t baudrate;                    // 8
    uint8_t return_delay_time;           // 9
    uint8_t drive_mode;                  // 10
    uint8_t operating_mode;              // 11
    uint8_t secondary_id;                // 12
    uint8_t protocol_version;            // 13
    uint8_t reserved_14_19[6];           // 14-19
    int32_t homing_offset;               // 20
    uint32_t moving_threshold;           // 24
    uint8_t reserved_28_30[3];           // 28-30
    uint8_t temperature_limit;           // 31
    uint16_t max_voltage_limit;          // 32
    uint16_t min_voltage_limit;          // 34
    uint16_t pwm_limit;                  // 36
    uint16_t current_limit;              // 38
    uint32_t acceleration_limit;         // 40
    uint32_t velocity_limit;             // 44
    uint32_t max_position_limit;         // 48
    uint32_t min_position_limit;         // 52
    uint8_t external_port_mode_1;        // 56
    uint8_t external_port_mode_2;        // 57
    uint8_t external_port_mode_3;        // 58
    uint8_t reserved_59_62[4];           // 59-62
    uint8_t shutdown;                    // 63
    uint8_t torque_enable;               // 64
    uint8_t led;                         // 65
    uint8_t reserved_66_67[2];           // 66-67
    uint8_t status_return_level;         // 68
    uint8_t registered_instruction;      // 69
    uint8_t hardware_error_status;       // 70
    uint8_t reserved_71_75[5];           // 71-75
    uint16_t velocity_i_gain;            // 76
    uint16_t velocity_p_gain;            // 78
    uint16_t position_d_gain;            // 80
    uint16_t position_i_gain;            // 82
    uint16_t position_p_gain;            // 84
    uint8_t reserved_86_87[2];           // 86-87
    uint16_t feedforward_acceleration_gain;  // 88
    uint16_t feedforward_velocity_gain;  // 90
    uint8_t reserved_92_97[6];           // 92-97
    int8_t bus_watchdog;                 // 98
    uint8_t reserved_99;                 // 99
    int16_t goal_pwm;                    // 100
    int16_t goal_current;                // 102
    int32_t goal_velocity;               // 104
    uint32_t profile_acceleration;       // 108
    uint32_t profile_velocity;           // 112
    int32_t goal_position;               // 116
    uint16_t realtime_tick;              // 120
    uint8_t moving;                      // 122
    uint8_t moving_status;               // 123
    int16_t present_pwm;                 // 124
    int16_t present_current;             // 126
    int32_t present_velocity;            // 128
    int32_t present_position;            // 132
    int32_t velocity_trajectory;         // 136
    int32_t position_trajectory;         // 140
    uint16_t present_input_voltage;      // 144
    uint8_t present_temperature;         // 146
} ControlTable;


extern void set_control_table_value(uint16_t address, uint32_t value);
extern uint32_t get_control_table_value(uint16_t address);

#endif // CONTROL_TABLE_H
