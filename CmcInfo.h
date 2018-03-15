#ifndef CMCINFO_H
#define CMCINFO_H

typedef std::vector<std::string> StringList;

struct CmcInfo {
        std::string clusterName;
        StringList providerNames, consumerNames;

        bool operator==(CmcInfo const &c) const {
                return clusterName == c.clusterName;
        }

	CmcInfo(const CmcInfo& ci) {
		clusterName = ci.clusterName;
		providerNames = ci.providerNames;
		consumerNames = ci.consumerNames;
	}
	CmcInfo() { }
};

CmcInfo provideData();

CmcInfo giveData();

#endif

