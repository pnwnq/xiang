#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <stdbool.h>

// 测试结果结构体
typedef struct {
    bool passed;
    char message[256];
} TestResult;

// 测试用例函数指针类型
typedef TestResult (*TestCase)(void);

// 测试套件结构体
typedef struct {
    char name[64];
    TestCase *cases;
    int count;
} TestSuite;

// 测试框架函数声明
void run_test_suite(TestSuite *suite);
void assert_true(bool condition, char *message, TestResult *result);
void assert_equals_int(int expected, int actual, char *message, TestResult *result);
void assert_equals_float(float expected, float actual, float epsilon, char *message, TestResult *result);

#endif 