#include "test_framework.h"
#include "motor_test.h"
#include "jy901_test.h"

int main() {
    printf("开始运行测试...\n");

    // 运行电机测试套件
    TestSuite motor_suite = get_motor_test_suite();
    run_test_suite(&motor_suite);

    // 运行JY901测试套件
    TestSuite jy901_suite = get_jy901_test_suite();
    run_test_suite(&jy901_suite);

    return 0;
} 