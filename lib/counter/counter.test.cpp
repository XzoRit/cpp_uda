#include <counter/counter.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
using ::counter::decrement_action;
using ::counter::increment_action;
using ::counter::model;
using ::counter::reset_action;
using ::counter::update;
BOOST_AUTO_TEST_SUITE(test_suite_counter);
BOOST_AUTO_TEST_CASE(test_increment)
{
    const auto value{0};
    BOOST_CHECK(update(model{.value = value}, increment_action{}) ==
                model{.value = value + 1});
}
BOOST_AUTO_TEST_CASE(test_decrement)
{
    const auto value{1};
    BOOST_CHECK(update(model{.value = value}, decrement_action{}) ==
                model{.value = value - 1});
}
BOOST_AUTO_TEST_CASE(test_reset)
{
    const auto value{0};
    const auto reset_value{10};
    BOOST_CHECK(
        update(model{.value = value}, reset_action{.new_value = reset_value}) ==
        model{.value = reset_value});
}
BOOST_AUTO_TEST_SUITE_END();
}
