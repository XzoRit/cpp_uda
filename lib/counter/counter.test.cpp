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
    BOOST_CHECK(update(model{.value = 0}, increment_action{}) ==
                model{.value = 1});
}
BOOST_AUTO_TEST_CASE(test_decrement)
{
    BOOST_CHECK(update(model{.value = 1}, decrement_action{}) ==
                model{.value = 0});
}
BOOST_AUTO_TEST_CASE(test_reset)
{
    BOOST_CHECK(update(model{.value = 0}, reset_action{.new_value = 10}) ==
                model{.value = 10});
}
BOOST_AUTO_TEST_SUITE_END();
}
