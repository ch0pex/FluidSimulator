#include <gtest/gtest.h>

#include "sim/proargs.hpp"
#include <span>


namespace sim {
  TEST(ProargsTest, CheckCountValidArgs) {
    const char* args[] = {"prog_name", "10", "init_path", "final_path"};
    const Proargs parser(std::span<const char*>(args, 4));
    EXPECT_EQ(0, parser.CheckCount());
  }

  TEST(ProargsTest, CheckCountInvalidArgs) {
    const char* args[] = {"prog_name", "10", "init_path"};
    const Proargs parser(std::span<const char*>(args, 3));
    EXPECT_EQ(-1, parser.CheckCount());
  }

  TEST(ProargsTest, CheckNtsValidValue) {
    int nts_value = 0;
    const char* args[] = {"prog_name", "10", "init_path", "final_path"};
    Proargs parser(std::span<const char*>(args, 4));
    EXPECT_EQ(0, parser.CheckNts(nts_value));
    EXPECT_EQ(10, nts_value);
  }

  TEST(ProargsTest, CheckNtsNonNumeric) {
    const char* args[] = {"prog_name", "abc", "init_path", "final_path"};
    Proargs parser(std::span<const char*>(args, 4));
    int nts = 0;
    EXPECT_EQ(-1, parser.CheckNts(nts));
  }

  TEST(ProargsTest, CheckNtsNegativeValue) {
    int nts_value = 0;
    const char* args[] = {"prog_name", "-10", "init_path", "final_path"};
    Proargs parser(std::span<const char*>(args, 4));
    EXPECT_EQ(-2, parser.CheckNts(nts_value));
  }
} // namespace sim
