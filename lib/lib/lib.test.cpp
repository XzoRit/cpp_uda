#include <lib/lib.hpp>

#include <boost/ut.hpp>

namespace
{
using namespace boost::ut;

suite errors = [] { "increment"_test = [] { expect(1_i == 1_i); }; };
}
