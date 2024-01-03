#include "user_header/control_table.h"
#include <stddef.h>
#include <string.h>

ControlTable control_table;
uint32_t DEBUG_table_pointer=0;
uint32_t DEBUG_offset_pointer=0;
uint32_t DEBUG_target_pointer=0;
void set_control_table_value(uint16_t address, uint32_t value) {
    switch (address) {
        case 0:
            control_table.model_number = (uint16_t)value;
            break;
        case 2:
            control_table.model_information = value;
            break;
        case 6:
            control_table.version_of_firmware = (uint8_t)value;
            break;
        case 7:
            control_table.id = (uint8_t)value;
            break;
        case 8:
            control_table.baudrate = (uint8_t)value;
            break;
        case 9:
            control_table.return_delay_time = (uint8_t)value;
            break;
        case 10:
            control_table.drive_mode = (uint8_t)value;
            break;
        case 11:
            control_table.operating_mode = (uint8_t)value;
            break;
        case 12:
            control_table.secondary_id = (uint8_t)value;
            break;
        case 13:
            control_table.protocol_version = (uint8_t)value;
            break;
        case 14: // reserved_14_19[0]
        case 15: // reserved_14_19[1]
        case 16: // reserved_14_19[2]
        case 17: // reserved_14_19[3]
        case 18: // reserved_14_19[4]
        case 19: // reserved_14_19[5]
            control_table.reserved_14_19[address - 14] = (uint8_t)value;
            break;
        case 20:
            control_table.homing_offset = (int32_t)value;
            break;
        case 24:
            control_table.moving_threshold = value;
            break;
        case 28: // reserved_28_30[0]
        case 29: // reserved_28_30[1]
        case 30: // reserved_28_30[2]
            control_table.reserved_28_30[address - 28] = (uint8_t)value;
            break;
        case 31:
            control_table.temperature_limit = (uint8_t)value;
            break;
        case 32:
            control_table.max_voltage_limit = (uint16_t)value;
            break;
        case 34:
            control_table.min_voltage_limit = (uint16_t)value;
            break;
        case 36:
            control_table.pwm_limit = (uint16_t)value;
            break;
        case 38:
            control_table.current_limit = (uint16_t)value;
            break;
        case 40:
            control_table.acceleration_limit = value;
            break;
        case 44:
            control_table.velocity_limit = value;
            break;
        case 48:
            control_table.max_position_limit = value;
            break;
        case 52:
            control_table.min_position_limit = value;
            break;
        case 56:
            control_table.external_port_mode_1 = (uint8_t)value;
            break;
        case 57:
            control_table.external_port_mode_2 = (uint8_t)value;
            break;
        case 58:
            control_table.external_port_mode_3 = (uint8_t)value;
            break;
        case 59: // reserved_59_62[0]
        case 60: // reserved_59_62[1]
        case 61: // reserved_59_62[2]
        case 62: // reserved_59_62[3]
            control_table.reserved_59_62[address - 59] = (uint8_t)value;
            break;
        case 63:
            control_table.shutdown = (uint8_t)value;
            break;
        case 64:
            control_table.torque_enable = (uint8_t)value;
            break;
        case 65:
            control_table.led = (uint8_t)value;
            break;
        case 66: // reserved_66_67[0]
        case 67: // reserved_66_67[1]
            control_table.reserved_66_67[address - 66] = (uint8_t)value;
            break;
        case 68:
            control_table.status_return_level = (uint8_t)value;
            break;
        case 69:
            control_table.registered_instruction = (uint8_t)value;
            break;
        case 70:
            control_table.hardware_error_status = (uint8_t)value;
            break;
        case 71: // reserved_71_75[0]
        case 72: // reserved_71_75[1]
        case 73: // reserved_71_75[2]
        case 74: // reserved_71_75[3]
        case 75: // reserved_71_75[4]
            control_table.reserved_71_75[address - 71] = (uint8_t)value;
            break;
        case 76:
            control_table.velocity_i_gain = (uint16_t)value;
            break;
        case 78:
            control_table.velocity_p_gain = (uint16_t)value;
            break;
        case 80:
            control_table.position_d_gain = (uint16_t)value;
            break;
        case 82:
            control_table.position_i_gain = (uint16_t)value;
            break;
        case 84:
            control_table.position_p_gain = (uint16_t)value;
            break;
        case 86: // reserved_86_87[0]
        case 87: // reserved_86_87[1]
            control_table.reserved_86_87[address - 86] = (uint8_t)value;
            break;
        case 88:
            control_table.feedforward_acceleration_gain = (uint16_t)value;
            break;
        case 90:
            control_table.feedforward_velocity_gain = (uint16_t)value;
            break;
        case 92: // reserved_92_97[0]
        case 93: // reserved_92_97[1]
        case 94: // reserved_92_97[2]
        case 95: // reserved_92_97[3]
        case 96: // reserved_92_97[4]
        case 97: // reserved_92_97[5]
            control_table.reserved_92_97[address - 92] = (uint8_t)value;
            break;
        case 98:
            control_table.bus_watchdog = (int8_t)value;
            break;
        case 99:
            control_table.reserved_99 = (uint8_t)value;
            break;
        case 100:
            control_table.goal_pwm = (int16_t)value;
            break;
        case 102:
            control_table.goal_current = (int16_t)value;
            break;
        case 104:
            control_table.goal_velocity = (int32_t)value;
            break;
        case 108:
            control_table.profile_acceleration = value;
            break;
        case 112:
            control_table.profile_velocity = value;
            break;
        case 116:
            control_table.goal_position = (int32_t)value;
            break;
        case 120:
            control_table.realtime_tick = (uint16_t)value;
            break;
        case 122:
            control_table.moving = (uint8_t)value;
            break;
        case 123:
            control_table.moving_status = (uint8_t)value;
            break;
        case 124:
            control_table.present_pwm = (int16_t)value;
            break;
        case 126:
            control_table.present_current = (int16_t)value;
            break;
        case 128:
            control_table.present_velocity = (int32_t)value;
            break;
        case 132:
            control_table.present_position = (int32_t)value;
            break;
        case 136:
            control_table.velocity_trajectory = (int32_t)value;
            break;
        case 140:
            control_table.position_trajectory = (int32_t)value;
            break;
        case 144:
            control_table.present_input_voltage = (uint16_t)value;
            break;
        case 146:
            control_table.present_temperature = (uint8_t)value;
            break;
        default:
            // Invalid address
            break;
    }
}
uint32_t get_control_table_value(uint16_t address) {
    switch (address) {
        case 0:
            return control_table.model_number;
        case 2:
            return control_table.model_information;
        case 6:
            return control_table.version_of_firmware;
        case 7:
            return control_table.id;
        case 8:
            return control_table.baudrate;
        case 9:
            return control_table.return_delay_time;
        case 10:
            return control_table.drive_mode;
        case 11:
            return control_table.operating_mode;
        case 12:
            return control_table.secondary_id;
        case 13:
            return control_table.protocol_version;
        case 14: // reserved_14_19[0]
        case 15: // reserved_14_19[1]
        case 16: // reserved_14_19[2]
        case 17: // reserved_14_19[3]
        case 18: // reserved_14_19[4]
        case 19: // reserved_14_19[5]
            return control_table.reserved_14_19[address - 14];
        case 20:
            return control_table.homing_offset;
        case 24:
            return control_table.moving_threshold;
        case 28: // reserved_28_30[0]
        case 29: // reserved_28_30[1]
        case 30: // reserved_28_30[2]
            return control_table.reserved_28_30[address - 28];
        case 31:
            return control_table.temperature_limit;
        case 32:
            return control_table.max_voltage_limit;
        case 34:
            return control_table.min_voltage_limit;
        case 36:
            return control_table.pwm_limit;
        case 38:
            return control_table.current_limit;
        case 40:
            return control_table.acceleration_limit;
        case 44:
            return control_table.velocity_limit;
        case 48:
            return control_table.max_position_limit;
        case 52:
            return control_table.min_position_limit;
        case 56:
            return control_table.external_port_mode_1;
        case 57:
            return control_table.external_port_mode_2;
        case 58:
            return control_table.external_port_mode_3;
        case 59: // reserved_59_62[0]
        case 60: // reserved_59_62[1]
        case 61: // reserved_59_62[2]
        case 62: // reserved_59_62[3]
            return control_table.reserved_59_62[address - 59];
        case 63:
            return control_table.shutdown;
        case 64:
            return control_table.torque_enable;
        case 65:
            return control_table.led;
        case 66: // reserved_66_67[0]
            return control_table.reserved_66_67[0];
        case 67: // reserved_66_67[1]
            return control_table.reserved_66_67[1];
        case 68:
            return control_table.status_return_level;
        case 69:
            return control_table.registered_instruction;
        case 70:
            return control_table.hardware_error_status;
        case 71: // reserved_71_75[0]
            return control_table.reserved_71_75[0];
        case 72: // reserved_71_75[1]
            return control_table.reserved_71_75[1];
        case 73: // reserved_71_75[2]
            return control_table.reserved_71_75[2];
        case 74: // reserved_71_75[3]
            return control_table.reserved_71_75[3];
        case 75: // reserved_71_75[4]
            return control_table.reserved_71_75[4];
        case 76:
            return control_table.velocity_i_gain;
        case 78:
            return control_table.velocity_p_gain;
        case 80:
            return control_table.position_d_gain;
        case 82:
            return control_table.position_i_gain;
        case 84:
            return control_table.position_p_gain;
        case 86: // reserved_86_87[0]
            return control_table.reserved_86_87[0];
        case 87: // reserved_86_87[1]
            return control_table.reserved_86_87[1];
        case 88:
            return control_table.feedforward_acceleration_gain;
        case 90:
            return control_table.feedforward_velocity_gain;
        case 92: // reserved_92_97[0]
            return control_table.reserved_92_97[0];
        case 93: // reserved_92_97[1]
            return control_table.reserved_92_97[1];
        case 94: // reserved_92_97[2]
            return control_table.reserved_92_97[2];
        case 95: // reserved_92_97[3]
            return control_table.reserved_92_97[3];
        case 96: // reserved_92_97[4]
            return control_table.reserved_92_97[4];
        case 97: // reserved_92_97[5]
            return control_table.reserved_92_97[5];
        case 98:
            return control_table.bus_watchdog;
        case 99:
            return control_table.reserved_99;
        case 100:
            return control_table.goal_pwm;
        case 102:
            return control_table.goal_current;
        case 104:
            return control_table.goal_velocity;
        case 108:
            return control_table.profile_acceleration;
        case 112:
            return control_table.profile_velocity;
        case 116:
            return control_table.goal_position;
        case 120:
            return control_table.realtime_tick;
        case 122:
            return control_table.moving;
        case 123:
            return control_table.moving_status;
        case 124:
            return control_table.present_pwm;
        case 126:
            return control_table.present_current;
        case 128:
            return control_table.present_velocity;
        case 132:
            return control_table.present_position;
        case 136:
            return control_table.velocity_trajectory;
        case 140:
            return control_table.position_trajectory;
        case 144:
            return control_table.present_input_voltage;
        case 146:
            return control_table.present_temperature;
        default:
            // Invalid address
            return 0;
    }
}


//パディング問題の回避策が分からなかったのでべた書きに変更
//void set_control_table_value(uint16_t address, uint32_t value) {
//    // Control tableのアドレス範囲内か確認
//    if (address >= sizeof(ControlTable)) {
//        return;
//    }
//
//    // アドレスに対応する構造体メンバーのサイズを取得
//    size_t size = 0;
//    if (address < 2) {
//        size = 2;
//    } else if (address < 6) {
//        size = 4;
//    } else {
//        size = 1;
//    }
//    uint8_t one_byte=value<<24&0xFF;
//    // 値を設定
//    uint8_t *table_ptr = (uint8_t *)&control_table;
//    DEBUG_table_pointer=table_ptr;
//    DEBUG_offset_pointer=address;
//    DEBUG_target_pointer=table_ptr + address;
//    memcpy(table_ptr + address, &value, size);
//}

//uint32_t get_control_table_value(uint16_t address, uint16_t size) {
//    // Control tableのアドレス範囲内か確認
//    if (address >= sizeof(ControlTable)) {
//        return 0;
//    }
//
//    // アドレスに対応する構造体メンバーのサイズを取得
//    if (size != 1 && size != 2 && size != 4) {
//        return 0;
//    }
//
//    // 値を取得
//    uint8_t *table_ptr = (uint8_t *)&control_table;
//    uint32_t value = 0;
//    memcpy(&value, table_ptr + address, size);
//    return value;
//}
