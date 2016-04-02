/*
 * _IndicatorImp.cpp
 *
 *  Created on: 2013-2-13
 *      Author: fasiondog
 */

#include <boost/python.hpp>
#include <hikyuu/indicator/Indicator.h>

using namespace boost::python;
using namespace hku;

class IndicatorImpWrap: public IndicatorImp, public wrapper<IndicatorImp> {
public:
    IndicatorImpWrap(): IndicatorImp() {}
    IndicatorImpWrap(const string& name): IndicatorImp(name) {}

    IndicatorImpPtr operator()(const Indicator& ind) {
        if (override call = get_override("__call__")) {
            return call(ind);
        }
        return IndicatorImp::operator()(ind);
    }

    IndicatorImpPtr default_call(const Indicator& ind) {
        return this->IndicatorImp::operator()(ind);
    }
};

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(_set_overloads, _set, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(_append_overloads, _append, 1, 2)

string (IndicatorImp::*read_name)() const = &IndicatorImp::name;
void (IndicatorImp::*write_name)(const string&) = &IndicatorImp::name;

void export_IndicatorImp() {
    class_<IndicatorImpWrap, boost::noncopyable>("IndicatorImp", init<>())
            .def(init<const string&>())
            .def(self_ns::str(self))
            .add_property("name", read_name, write_name)
            .add_property("discard", &IndicatorImp::discard)
            .def("setDiscard", &IndicatorImp::setDiscard)
            .def("_set", &IndicatorImp::_set, _set_overloads())
            .def("_readyBuffer", &IndicatorImp::_readyBuffer)
            .def("getResultNumber", &IndicatorImp::getResultNumber)
            .def("getResultAsPriceList", &IndicatorImp::getResultAsPriceList)
            .def("__call__", &IndicatorImp::operator(), &IndicatorImpWrap::default_call)
            ;

    register_ptr_to_python<IndicatorImpPtr>();
}

