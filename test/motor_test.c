#include "motor_test.h"

// 模拟电机控制函数
static int motor_speed = 0;
static bool motor_initialized = false;

static void motor_init(void) {
    motor_initialized = true;
}

static void motor_set_speed(int speed) {
    if (motor_initialized && speed >= -100 && speed <= 100) {
        motor_speed = speed;
    }
}

static int motor_get_speed(void) {
    return motor_speed;
}

static void motor_stop(void) {
    motor_speed = 0;
}

// 测试用例实现
TestResult test_motor_init(void) {
    TestResult result;
    motor_init();
    assert_true(motor_initialized, "电机初始化测试", &result);
    return result;
}

TestResult test_motor_set_speed(void) {
    TestResult result;
    motor_set_speed(50);
    assert_equals_int(50, motor_get_speed(), "电机设置速度测试", &result);
    return result;
}

TestResult test_motor_get_speed(void) {
    TestResult result;
    motor_set_speed(75);
    assert_equals_int(75, motor_get_speed(), "电机读取速度测试", &result);
    return result;
}

TestResult test_motor_emergency_stop(void) {
    TestResult result;
    motor_set_speed(100);
    motor_stop();
    assert_equals_int(0, motor_get_speed(), "电机紧急停止测试", &result);
    return result;
}

// 创建电机测试套件
TestSuite get_motor_test_suite(void) {
    static TestCase cases[] = {
        test_motor_init,
        test_motor_set_speed,
        test_motor_get_speed,
        test_motor_emergency_stop
    };
    
    TestSuite suite = {
        .name = "电机控制测试",
        .cases = cases,
        .count = sizeof(cases) / sizeof(cases[0])
    };
    
    return suite;
} 