#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <string>

const std::string SAVE_COMMAND = "save";
const std::string OPEN_COMMAND = "open";
const std::string HELP_COMMAND = "help";
const std::string SAVE_AS_COMMAND = "saveas";
const std::string CLOSE_COMMAND = "close";
const std::string EXIT_COMMAND = "exit";
const std::string USER_ALERT_MESSAGE = "Type \"open <path>\" to open a file\n";

const std::string FILE_CLOSED_MESSAGE = "Successfully closed ";
const std::string FILE_SAVED_MESSAGE = "Successfully saved ";
const std::string FILE_OPENED_MESSAGE = "Successfully opened ";
const std::string FILE_ERROR_MESSAGE = "Error creating file. Check if the specified path is correct and try again.";

const std::string VALUE_ID = "id=\"";
const std::string VALUE_CAPACITY = "capacity=\"";
const std::string VALUE_NAME = "name=\"";
const std::string VALUE_EXPIRATION_DATE = "expiration_date=\"";
const std::string VALUE_ENTRY_DATE = "name=\"";
const std::string VALUE_MANUFACTURER_NAME = "name=\"";
const std::string VALUE_UNIT_OF_MEASUREMENT = "name=\"";
const std::string VALUE_AVAILABLE_QUANTITY = "name=\"";
const std::string VALUE_SECTION = "name=\"";
const std::string VALUE_COMMENT = "name=\"";
#endif
