#pragma once
#include "ID.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Logger.h"
#include "Assert.h"
#include "Resource.h"
#include <XML/rapidxml_utils.hpp>

using namespace Logger;
using namespace rapidxml;

static vector <int> xmlValues;

static void XML(int dificultad) {

	rapidxml::xml_document<> doc;
	std::ifstream file("config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	rapidxml::xml_node<> *pRoot;
	pRoot = doc.first_node(); 
	rapidxml::xml_node<> *pNode;


	if (dificultad == 1) {
		pNode = pRoot->first_node("easy"); 
		int i = 0;
		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			xmlValues.push_back(stoi(pAttr->value()));
			i++;
		}
	}

	else if (dificultad == 2) {

		pNode = pRoot->first_node("medium");

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			xmlValues.push_back(stoi(pAttr->value()));
		}

	}
	else if (dificultad == 3) {


		pNode = pRoot->first_node("hard"); 

		for (rapidxml::xml_node<> *pAttr = pNode->first_node(); pAttr; pAttr = pAttr->next_sibling()) {
			xmlValues.push_back(stoi(pAttr->value()));
		}
	}
}