#include <console/console.hpp>
#include <counter/counter.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
::counter::model dispatch(::counter::model m, char ev)
{
    return ::counter::update(m, ::console::intent(ev).value());
}
BOOST_AUTO_TEST_SUITE(test_suite_console);
BOOST_AUTO_TEST_CASE(test_increment)
{
    ::counter::model m{0};
    m = dispatch(m, '+');
    BOOST_TEST(m.value == 1);
}
BOOST_AUTO_TEST_CASE(test_decrement)
{
    ::counter::model m{2};
    m = dispatch(m, '-');
    BOOST_TEST(m.value == 1);
}
BOOST_AUTO_TEST_CASE(test_reset)
{
    ::counter::model m{2};
    m = dispatch(m, '.');
    BOOST_TEST(m.value == 0);
}
BOOST_AUTO_TEST_SUITE_END();
}
