#include "gadget.h"

std::string MakeSafeName(std::string safe_name){
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '('), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ')'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '\\'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '/'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '['), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ']'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '+'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '-'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '*'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '.'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ' '), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ','), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '|'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ':'), safe_name.end());

	return safe_name;
};

void buildfolder( std::string name){
	std::cout<<"Starting "<<name<<std::endl;
	if (access(name.c_str(),F_OK) == -1){
		mkdir(name.c_str(),0777);//Create a folder for pdf.
	}
	else{
		std::cout<<"Overwrite "<<name<<"/ in 2 seconds, 1 seconds, ..."<<std::endl;
	}
};

bool boolreader( const char* text){

	if (strcmp(text ,"yes")==0||strcmp(text,"true")==0) return true;
	
	return false;

}

std::vector< TString > tokenizer( const char* text){
	
	bool debug = true;

	if(debug)	std::cout<<"CHECK Tokenize input: "<<text<< "."<<std::endl;

	std::vector< TString > tokens;

	if(!text) return {""};

	std::stringstream acopy(text);
	std::string temp_s;
	bool no_comma = true;

	while(getline(acopy, temp_s, ',')){
		no_comma = false;
		tokens.push_back(temp_s);
		if(debug)std::cout<<temp_s<<std::endl;
	}

	if(no_comma){
		getline(acopy, temp_s);
		tokens.push_back(temp_s);
	}

	return tokens;

}
