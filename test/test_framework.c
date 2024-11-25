#include "test_framework.h"
#include <string.h>

void run_test_suite(TestSuite *suite) {
    printf("\n=== 运行测试套件: %s ===\n", suite->name);
    int passed = 0;
    
    for (int i = 0; i < suite->count; i++) {
        TestResult result = suite->cases[i]();
        if (result.passed) {
            printf("✓ 测试通过: %s\n", result.message);
            passed++;
        } else {
            printf("✗ 测试失败: %s\n", result.message);
        }
    }
    
    printf("\n总结: %d/%d 测试通过\n", passed, suite->count);
}

void assert_true(bool condition, char *message, TestResult *result) {
    result->passed = condition;
    strcpy(result->message, message);
}

void assert_equals_int(int expected, int actual, char *message, TestResult *result) {
    result->passed = (expected == actual);
    if (result->passed) {
        strcpy(result->message, message);
    } else {
        sprintf(result->message, "%s (期望值: %d, 实际值: %d)", message, expected, actual);
    }
}

void assert_equals_float(float expected, float actual, float epsilon, char *message, TestResult *result) {
    result->passed = (fabs(expected - actual) < epsilon);
    if (result->passed) {
        strcpy(result->message, message);
    } else {
        sprintf(result->message, "%s (期望值: %.3f, 实际值: %.3f)", message, expected, actual);
    }
} 