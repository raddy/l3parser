#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>

#include "structs.hpp"
#include "l3parser.hpp"

namespace py = pybind11;

PYBIND11_MODULE(l3parser, m) {
    m.doc() = R"pbdoc(
        LL PARSER
        -----------------------
        .. currentmodule:: ??
        .. autosummary::
           :toctree: _generate
           add
           subtract
    )pbdoc";

    PYBIND11_NUMPY_DTYPE(TradeUpdate, _side, _tick_type,_liquidation_type,
                         _px, _qty, _timestamp, _local_time);
    PYBIND11_NUMPY_DTYPE(FundingUpdate, _rate, _timestamp, _local_time);
    PYBIND11_NUMPY_DTYPE(L2Book, _bp, _bz, _ap, _az, _local_time);
    PYBIND11_NUMPY_DTYPE(LiquidationBook, _bp, _bz, _ap, _az, _local_time);
    PYBIND11_NUMPY_DTYPE(PriceUpdate, _settlement_price, _mark_price, _index_price, _rate, _timestamp, _local_time);

    py::class_<L3Parser>(m, "L3Parser")
        .def(py::init<std::string, std::string>())
        .def("add_message", &L3Parser::add_message)
        .def("books", &L3Parser::books);


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}