#ifndef BOOST_MODULES_H
#define BOOST_MODULES_H

#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

namespace python = boost::python;

BOOST_PYTHON_MODULE(cmc) {
	python::class_<CmcInfo>("CmcInfo", python::init<>())
		.add_property("clusterName", &CmcInfo::clusterName)
		.add_property("providerNames", &CmcInfo::providerNames)
		.add_property("consumerNames", &CmcInfo::consumerNames)
	;

	python::class_<StringList>("StringList")
		.def(boost::python::vector_indexing_suite<StringList> ())
	;

}
#endif
