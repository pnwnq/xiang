#ifndef MOTOR_TEST_H
#define MOTOR_TEST_H

#include "test_framework.h"

// 电机测试用例声明
TestResult test_motor_init(void);
TestResult test_motor_set_speed(void);
TestResult test_motor_get_speed(void);
TestResult test_motor_emergency_stop(void);

// 获取电机测试套件
TestSuite get_motor_test_suite(void);

#endif 