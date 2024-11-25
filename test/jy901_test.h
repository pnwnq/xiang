#ifndef JY901_TEST_H
#define JY901_TEST_H

#include "test_framework.h"

// JY901陀螺仪测试用例声明
TestResult test_jy901_init(void);
TestResult test_jy901_data_collection(void);
TestResult test_jy901_calibration(void);
TestResult test_jy901_angle_output(void);
TestResult test_jy901_stop_output(void);

// 获取JY901测试套件
TestSuite get_jy901_test_suite(void);

#endif 