#include "insurance.h"

std::string Insurance::getCarrier() const {

	return carrier_;
}

std::string Insurance::getGroup() const {

	return group_;
}

std::string Insurance::getPolicy() const {

	return policy_;
}

Beneficiary Insurance::getBeneficiary() const {

	return beneficiary_;
}

void Insurance::setCarrier(const std::string& carrierParam) {

	if(carrierParam.length() != CARRIERLENGTH)
		return;

	carrier_ = carrierParam;
}

void Insurance::setGroup(const std::string& groupParam) {

	if(groupParam.length() > MAXGROUPLENGTH)
		return;

	group_ = groupParam;
}

void Insurance::setPolicy(const std::string& policyParam) {

	if(policyParam.length() > MAXPOLICYLENGTH)
		return;

	policy_ = policyParam;
}

void Insurance::setBeneficiary(Beneficiary beneficiaryParam) {

	beneficiary_ = beneficiaryParam;
}
