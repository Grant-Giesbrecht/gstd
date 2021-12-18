#ifndef GLOGGER_HPP
#define GLOGGER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "gcolors.hpp"

#define LOGGER_DEBUG 10
#define LOGGER_INFO 20
#define LOGGER_MSG 30
#define LOGGER_WARNING 40
#define LOGGER_ERROR 50
#define LOGGER_CRITICAL 60

class GLogger{

public:

	GLogger();

	void debug(std::string logtxt);
	void info(std::string logtxt);
	void msg(std::string logtxt, bool printNow=false);
	void warning(std::string logtxt, bool printNow=false);
	void error(std::string logtxt, bool printNow=false);

	void lmsg(std::string logtxt, size_t lnum, bool printNow=false);
	void lwarning(std::string logtxt, size_t lnum, bool printNow=false);
	void lerror(std::string logtxt, size_t lnum, bool printNow=false);

	void critical(std::string logtxt);

	void setLevel(int lvl);
	void get();
	std::string all();

	int level;
	bool show_criticals;

	std::vector<std::string> messages;
	std::vector<std::string> infos;
	std::vector<std::string> debugs;
	std::vector<std::string> warnings;
	std::vector<std::string> errors;
	std::vector<std::string> criticals;

};

GLogger::GLogger(){

	level = LOGGER_MSG;
	show_criticals = true;

}

void GLogger::debug(std::string logtxt){

	debugs.push_back(logtxt);

}

void GLogger::setLevel(int lvl){
	level = lvl;
}

void GLogger::info(std::string logtxt){

	infos.push_back(logtxt);

}

void GLogger::msg(std::string logtxt, bool printNow){

	messages.push_back(logtxt);

	if (printNow){
		std::cout << "\t" + gstd::gcolor::blue + logtxt + gstd::gcolor::normal << std::endl;
	}

}

void GLogger::lmsg(std::string logtxt, size_t lnum, bool printNow){

	logtxt = "[Line: " + std::to_string(lnum) + "] ";

	messages.push_back(logtxt);

	if (printNow){
		std::cout << "\t" + gstd::gcolor::blue + logtxt + gstd::gcolor::normal << std::endl;
	}

}

void GLogger::warning(std::string logtxt, bool printNow){

	warnings.push_back(logtxt);

	if (printNow){
		std::cout << gstd::gcolor::yellow << "WARNING: " << logtxt << gstd::gcolor::normal << std::endl;
	}
}

void GLogger::lwarning(std::string logtxt, size_t lnum, bool printNow){

	logtxt = "[Line: " + std::to_string(lnum) + "] ";

	warnings.push_back(logtxt);

	if (printNow){
		std::cout << gstd::gcolor::yellow << "WARNING: " << logtxt << gstd::gcolor::normal << std::endl;
	}
}

void GLogger::error(std::string logtxt, bool printNow){

	errors.push_back(logtxt);

	if (printNow){
		std::cout << gstd::gcolor::red << "ERROR: " << logtxt << gstd::gcolor::normal << std::endl;
	}
}

void GLogger::lerror(std::string logtxt, size_t lnum, bool printNow){

	logtxt = "[Line: " + std::to_string(lnum) + "] ";

	errors.push_back(logtxt);

	if (printNow){
		std::cout << gstd::gcolor::red << "ERROR: " << logtxt << gstd::gcolor::normal << std::endl;
	}
}

void GLogger::critical(std::string logtxt){

	criticals.push_back(logtxt);

	if (show_criticals){
		std::cout << gstd::gcolor::redBg << gstd::gcolor::black << "****************************************************************" << gstd::gcolor::normal << std::endl;
		std::cout << gstd::gcolor::redBg << gstd::gcolor::black << "CRITICAL: " << logtxt << gstd::gcolor::normal << std::endl;
		std::cout << gstd::gcolor::redBg << gstd::gcolor::black << "****************************************************************" << gstd::gcolor::normal << std::endl;
	}


}

std::string GLogger::all(){

	std::string out;

	if (messages.size() > 0){
		out = out + "Messages:\n";
		for (size_t i = 0 ; i < messages.size() ; i++){
			out = out + "\t" + gstd::gcolor::blue + messages[i] + gstd::gcolor::normal + "\n";
		}
	}
	if (infos.size() > 0){
		out = out + "Info Logs:\n";
		for (size_t i = 0 ; i < infos.size() ; i++){
			out = out + "\t" + infos[i] + "\n";
		}
	}
	if (debugs.size() > 0){
		out = out + "Debug Logs:\n";
		for (size_t i = 0 ; i < debugs.size() ; i++){
			out = out + "\t" + debugs[i] + "\n";
		}
	}
	if (warnings.size() > 0){
		out = out + "Warnings:\n";
		for (size_t i = 0 ; i < warnings.size() ; i++){
			out = out + "\t" + gstd::gcolor::yellow + warnings[i] + gstd::gcolor::normal + "\n";
		}
	}
	if (errors.size() > 0){
		out = out + "Errors:\n";
		for (size_t i = 0 ; i < errors.size() ; i++){
			out = out + "\t" + gstd::gcolor::red + errors[i] + gstd::gcolor::normal + "\n";
		}
	}
	if (criticals.size() > 0){
		out = out + "Critical Errors:\n";
		for (size_t i = 0 ; i < criticals.size() ; i++){
			out = out + "\t" + gstd::gcolor::red + criticals[i] + gstd::gcolor::normal + "\n";
		}
	}

	return out;

}





#endif
