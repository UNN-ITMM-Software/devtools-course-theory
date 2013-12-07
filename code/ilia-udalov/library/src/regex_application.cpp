// Copyright 2013 Ilia Udalov

#include "library/regex_application.h"

#include <string>
#include <sstream>

#include "library/regex.h"

RegexApplication::RegexApplication() : message_("") {}

void RegexApplication::help(const char* appname) {
    message_ += std::string("This is a simple handler ")
        + "for regexps and substrings.\n"
        + "Please provide arguments in the following format:\n\n"
        + " $ %s <regexp> <substring> <text>"
        + " \n\n" + appname;
    return;
}

bool RegexApplication::parseArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        message_ = "ERROR: Wrong number of arguments!\n\n";
        help(argv[0]);
        return false;
    }

    return true;
}

std::string RegexApplication::operator()(int argc, const char** argv) {
    bool returnCode = parseArguments(argc, argv);
    if (returnCode != true)
        return message_;

    std::ostringstream stream;
    int is_match = match(argv[1], argv[3]);
    if (is_match) {
        stream << "Regexp: match.\n";
    } else {
        stream << "Regexp: does not match.\n";
    }

    int pos = find(argv[2], argv[3]);
    if (pos != -1) {
        stream << "Substring: first pos is: " << pos << ".\n";
    } else {
        stream << "Substring: does not found.\n";
    }

    message_ = stream.str();

    return message_;
}
