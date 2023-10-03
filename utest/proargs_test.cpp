#include "sim/proargs.hpp"

#include <gtest/gtest.h>
#include <span>

namespace sim {
  TEST(ProargsTest, CheckCountValidArgs) {
    char const * args[] = {"prog_name", "10", "init_path", "final_path"};
    Proargs const parser(std::span<char const *>(args, 4));
    EXPECT_EQ(0, parser.CheckCount());
  }

  TEST(ProargsTest, CheckCountInvalidArgs) {
    char const * args[] = {"prog_name", "10", "init_path"};
    Proargs const parser(std::span<char const *>(args, 3));
    EXPECT_EQ(-1, parser.CheckCount());
  }

  TEST(ProargsTest, CheckNtsValidValue) {
    int nts_value       = 0;
    char const * args[] = {"prog_name", "10", "init_path", "final_path"};
    Proargs parser(std::span<char const *>(args, 4));
    EXPECT_EQ(0, parser.CheckNts(nts_value));
    EXPECT_EQ(10, nts_value);
  }

  TEST(ProargsTest, CheckNtsNonNumeric) {
    char const * args[] = {"prog_name", "abc", "init_path", "final_path"};
    Proargs parser(std::span<char const *>(args, 4));
    int nts = 0;
    EXPECT_EQ(-1, parser.CheckNts(nts));
  }

  TEST(ProargsTest, CheckNtsNegativeValue) {
    int nts_value       = 0;
    char const * args[] = {"prog_name", "-10", "init_path", "final_path"};
    Proargs parser(std::span<char const *>(args, 4));
    EXPECT_EQ(-2, parser.CheckNts(nts_value));
  }
}  // namespace sim
