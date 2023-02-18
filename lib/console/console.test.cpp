#include <console/console.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
BOOST_AUTO_TEST_SUITE(test_suite_console);
BOOST_AUTO_TEST_CASE(test_dummy)
{
    BOOST_CHECK(1 == 1);
}
BOOST_AUTO_TEST_SUITE_END();
}
