#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <string>

//TODO CHECK IF STRING IS GOOD TO BE USED HERE INSTEAD OF CHAR ARRAY

const std::string SAVE_COMMAND = "save";
const std::string OPEN_COMMAND = "open";
const std::string HELP_COMMAND = "help";
const std::string SAVE_AS_COMMAND = "saveas";
const std::string CLOSE_COMMAND = "close";
const std::string EXIT_COMMAND = "exit";
const std::string PRINT_COMMAND = "print";
const std::string ADD_COMMAND = "add";
const std::string LOG_COMMAND = "log";
const std::string CLEAN_COMMAND = "clean";
const std::string REMOVE_COMMAND = "remove";
const std::string USER_ALERT_MESSAGE = "Type \"open <path>\" to open a file\n";

const std::string FILE_CLOSED_MESSAGE = "Successfully closed ";
const std::string FILE_SAVED_MESSAGE = "Successfully saved ";
const std::string FILE_OPENED_MESSAGE = "Successfully opened ";
const std::string FILE_ERROR_MESSAGE = "Error opening file. Check if the specified path is correct and try again.";

const std::string CURRENT_DATE = "2020-05-07";
#endif
