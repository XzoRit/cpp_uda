#include <counter/counter.hpp>
#include <imgui/imgui.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
BOOST_AUTO_TEST_SUITE(test_suite_imgui);
BOOST_AUTO_TEST_CASE(test_one)
{
    ::counter::model m{0};
    BOOST_TEST(m.value == 0);
}
BOOST_AUTO_TEST_SUITE_END();
}
