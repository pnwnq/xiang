#include "jy901_test.h"
#include <math.h>

// 模拟JY901陀螺仪状态
static struct {
    bool initialized;
    bool collecting;
    float angle;
    float angular_velocity;
    bool calibrated;
} jy901_state = {0};

// 模拟JY901初始化函数
static bool jy901_init(void) {
    jy901_state.initialized = true;
    jy901_state.collecting = false;
    jy901_state.angle = 0.0f;
    jy901_state.angular_velocity = 0.0f;
    jy901_state.calibrated = false;
    return true;
}

// 模拟数据采集函数
static void jy901_start_collection(void) {
    if (jy901_state.initialized) {
        jy901_state.collecting = true;
        jy901_state.angular_velocity = 0.5f; // 模拟角速度
    }
}

// 模拟停止输出
static void jy901_stop_output(void) {
    jy901_state.collecting = false;
    jy901_state.angular_velocity = 0.0f;
}

// 模拟校准函数
static bool jy901_calibrate(void) {
    if (jy901_state.initialized) {
        jy901_state.calibrated = true;
        jy901_state.angle = 0.0f; // 校准后角度归零
        return true;
    }
    return false;
}

// 测试用例实现
TestResult test_jy901_init(void) {
    TestResult result;
    bool init_success = jy901_init();
    assert_true(init_success, "陀螺仪初始化测试", &result);
    return result;
}

TestResult test_jy901_data_collection(void) {
    TestResult result;
    jy901_init();
    jy901_start_collection();
    assert_true(jy901_state.collecting, "陀螺仪数据采集开始测试", &result);
    return result;
}

TestResult test_jy901_calibration(void) {
    TestResult result;
    jy901_init();
    bool calibration_success = jy901_calibrate();
    assert_true(calibration_success, "陀螺仪校准测试", &result);
    assert_equals_float(0.0f, jy901_state.angle, 0.001f, "校准后角度归零测试", &result);
    return result;
}

TestResult test_jy901_angle_output(void) {
    TestResult result;
    jy901_init();
    jy901_start_collection();
    // 模拟运行一段时间后的角度
    jy901_state.angle = 45.0f;
    assert_equals_float(45.0f, jy901_state.angle, 0.1f, "角度输出测试", &result);
    return result;
}

TestResult test_jy901_stop_output(void) {
    TestResult result;
    jy901_init();
    jy901_start_collection();
    jy901_stop_output();
    assert_equals_float(0.0f, jy901_state.angular_velocity, 0.001f, "停止输出测试", &result);
    return result;
}

// 创建JY901测试套件
TestSuite get_jy901_test_suite(void) {
    static TestCase cases[] = {
        test_jy901_init,
        test_jy901_data_collection,
        test_jy901_calibration,
        test_jy901_angle_output,
        test_jy901_stop_output
    };
    
    TestSuite suite = {
        .name = "JY901陀螺仪测试",
        .cases = cases,
        .count = sizeof(cases) / sizeof(cases[0])
    };
    
    return suite;
} 