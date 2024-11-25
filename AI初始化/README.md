# Xiang - 机器人竞赛电控调试模板

## 项目简介
Xiang是一个为国内大学生机器人竞赛设计的电控调试模板项目。本项目提供了完整的测试流程和文档模板,帮助参赛队伍更高效地完成电控系统的调试工作。

## 主要功能
- 单元测试模板
- 集成测试流程
- 输入测试规范
- 系统测试指南
- 实地运行测试方案

## 测试框架
项目包含一个轻量级的C语言测试框架,位于`test`目录下:
- `test_framework.h/c`: 测试框架核心,提供断言和测试运行器
- `motor_test.h/c`: 电机控制模块测试示例
- `jy901_test.h/c`: JY901陀螺仪测试模块
- `main.c`: 测试程序入口

### 主要特性
- 支持测试套件(Test Suite)组织测试用例
- 提供多种断言函数:
  - `assert_true`: 布尔值断言
  - `assert_equals_int`: 整数相等断言
  - `assert_equals_float`: 浮点数相等断言
- 清晰的测试结果输出
- 模块化设计,易于扩展

### JY901陀螺仪测试模块
- 初始化测试
- 数据采集功能测试
- 校准功能测试
- 角度输出测试
- 停止输出测试

### 使用方法
1. 编译测试程序:
```bash
gcc -o test_runner test/*.c
```

2. 运行测试:
```bash
./test_runner
```

## 项目结构
```
xiang/
├── test/                   # 测试框架和测试用例
│   ├── test_framework.h    # 测试框架头文件
│   ├── test_framework.c    # 测试框架实现
│   ├── motor_test.h       # 电机测试头文件
│   ├── motor_test.c       # 电机测试实现
│   ├── jy901_test.h       # JY901陀螺仪测试头文件
│   ├── jy901_test.c       # JY901陀螺仪测试实现
│   └── main.c             # 测试主程序
├── docs/                   # 文档目录
└── src/                    # 源代码目录
```

## 使用指南
1. 克隆项目:
```bash
git clone https://github.com/pnwnq/xiang.git
```

2. 按照测试阶段进行:
   - 单元测试
   - 集成测试
   - 输入测试
   - 系统测试
   - 实地运行测试

## 文档结构
- `ProjectRequirements.md`: 项目需求文档
- `FunctionalDesign.md`: 功能设计文档
- `CodeChangeLog.md`: 代码变更日志
- `UpdateInstructions.md`: 更新说明文档

## 开发计划
- [x] 基础测试框架
- [x] 电机控制测试模块
- [ ] 传感器测试模块
- [ ] PID控制器测试模块
- [ ] 通信模块测试