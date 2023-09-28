#include "sim/proargs.hpp"

#include <gtest/gtest.h>

// Test fixture para la clase Proargs
class ProargsTest : public ::testing::Test {
protected:
    ProargsTest() {
        // Configura datos de prueba
        static const char* testArgs[] = {"program_name", "10", "input.txt", "output.txt"};
        argc_ = sizeof(testArgs) / sizeof(testArgs[0]);
        argv_ = const_cast<char**>(testArgs);
    }

    int argc_;
    char** argv_;
};

// Prueba que CheckCount() devuelve 0 para la cantidad correcta de argumentos
TEST_F(ProargsTest, CheckCountValid) {
    const sim::Proargs proargs(argc_, argv_);
    EXPECT_EQ(proargs.CheckCount(), 0);
}

// Prueba que CheckCount() devuelve -1 para una cantidad incorrecta de argumentos
TEST_F(ProargsTest, CheckCountInvalid) {
    const char* testArgs[] = {"program_name", "10", "input.txt"};
    argc_ = sizeof(testArgs) / sizeof(testArgs[0]);
    argv_ = const_cast<char**>(testArgs);
    const sim::Proargs proargs(argc_, argv_);
    EXPECT_EQ(proargs.CheckCount(), -1);
}

// Prueba que CheckNts() devuelve 0 para un valor nts válido
TEST_F(ProargsTest, CheckNtsValid) {
    int nts = 0;
    sim::Proargs proargs(argc_, argv_);
    EXPECT_EQ(proargs.CheckNts(nts), 0);
    EXPECT_EQ(nts, 10);
}

// Prueba que CheckNts() devuelve -1 para un valor nts no numérico
TEST_F(ProargsTest, CheckNtsNonNumeric) {
    int nts = 0;
    const char* testArgs[] = {"program_name", "abc", "input.txt", "output.txt"};
    argc_ = sizeof(testArgs) / sizeof(testArgs[0]);
    argv_ = const_cast<char**>(testArgs);
    sim::Proargs proargs(argc_, argv_);
    EXPECT_EQ(proargs.CheckNts(nts), -1);
}

// Prueba que CheckNts() devuelve -2 para un valor nts no válido (<= 0)
TEST_F(ProargsTest, CheckNtsInvalid) {
    int nts = 0;
    const char* testArgs[] = {"program_name", "0", "input.txt", "output.txt"};
    argc_ = sizeof(testArgs) / sizeof(testArgs[0]);
    argv_ = const_cast<char**>(testArgs);
    sim::Proargs proargs(argc_, argv_);
    EXPECT_EQ(proargs.CheckNts(nts), -2);
}

