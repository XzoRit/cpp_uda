#include <console/console.hpp>
#include <counter/counter.hpp>
#include <model/model.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
::model::model dispatch(::model::model m, char ev)
{
    return ::model::update(m, ::console::intent(ev).value());
}
BOOST_AUTO_TEST_SUITE(test_suite_console);
BOOST_AUTO_TEST_CASE(test_increment)
{
    BOOST_TEST(dispatch({.counter = ::counter::model{.value = 0}}, '+')
                   .counter.value == 1);
}
BOOST_AUTO_TEST_CASE(test_decrement)
{
    BOOST_TEST(dispatch({.counter = ::counter::model{.value = 2}}, '-')
                   .counter.value == 1);
}
BOOST_AUTO_TEST_CASE(test_reset)
{
    BOOST_TEST(dispatch({.counter = ::counter::model{.value = 2}}, '.')
                   .counter.value == 0);
}
BOOST_AUTO_TEST_SUITE_END();
}
