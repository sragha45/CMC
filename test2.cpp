#include <thread>
#include<iostream>
#include "CmcClusterMo.h"
#include "VcInterface.h"
#include <string>
#include <vector>
#include "CmcInfo.h"
#include "BoostModules.h"

python::object main_namespace;
string clusterName;
CmcClusterMo *cm;

CmcInfo getClusterDetails() {
	CmcInfo objCmcInfo;
	for(auto i: cm->memberProviderList)
		objCmcInfo.providerNames.push_back(i->getProviderIP());
	for(auto i: cm->memberConsumerList)
		objCmcInfo.consumerNames.push_back(i->getConsumerIP());
	objCmcInfo.clusterName = clusterName;
	return objCmcInfo;
}

void start_python_server() {
	PyImport_AppendInittab("cmc", &initcmc);
	Py_Initialize();

	python::object main_module = python::import("__main__");
	std::cout << "=====atleast here========\n" << std::flush;
	main_namespace = main_module.attr("__dict__");
	python::import("cmc");
	std::cout << "=====before call=====\n" << std::flush;
	CmcInfo objCmcInfo = getClusterDetails();
	std::cout << "=====after call=====\n" << std::flush;
	main_namespace["obj"] = objCmcInfo;
	python::exec_file("test.py", main_namespace);
}

int main()
{

 std::cout <<"\n Enter Cluster Name:\n";
 string clustername;
 std::cin >> clustername;
 clusterName = clustername;

 std::cout << "Input provider policy : 0 -> BestFit   1 -> RoundRobin \n";
 int policy ;
 std::cin >> policy;
 if(policy == 0)
     std::cout << "BestFit Policy is set \n";
 else if(policy ==1 )
     std::cout << "RoundRobin Policy is set \n";

 cm = new CmcClusterMo(clustername, policy);
 cm->init();
 cm->start();
 std::thread t(start_python_server);
 t.detach();
 while(1) {int s; std::cout << "input : "; std::cin >> s;cm->getclusterStats();}
}
